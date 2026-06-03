document.addEventListener("DOMContentLoaded", function () {
    setReceiptInfo();
    loadShoppingList();
    toggleButtons();

    const clearBtn = document.getElementById("clear-list-btn");
    if (clearBtn) {
        clearBtn.addEventListener("click", clearShoppingList);
    }

    const downloadBtn = document.getElementById("download-list-btn");
    if (downloadBtn) {
        downloadBtn.addEventListener("click", downloadShoppingList);
    }
});

const BASKET_IMAGE_RULES = [
    { keywords: ["cherry", "cherries", "fresh cherries"], id: "basket-cherries" },
    { keywords: ["chicken", "chicken thigh", "chicken thighs", "chicken breast"], id: "basket-chicken" },
    { keywords: ["egg", "eggs"], id: "basket-eggs" },
    { keywords: ["flour", "all-purpose flour"], id: "basket-flour" },
    { keywords: ["sugar", "white sugar"], id: "basket-sugar" },
    { keywords: ["milk"], id: "basket-milk" }
];

function setReceiptInfo() {
    const dateEl = document.getElementById("receipt-date");
    const nameEl = document.getElementById("receipt-name");

    if (dateEl) {
        const today = new Date();
        const formattedDate = today.toLocaleDateString("en-US", {
            month: "short",
            day: "numeric",
            year: "numeric"
        });
        dateEl.textContent = "DATE: " + formattedDate;
    }

    if (nameEl) {
        nameEl.textContent = "NAME: GUEST";

        // Fetch session details from CheckSessionServlet
        fetch('../check-session')
            .then(response => {
                if (!response.ok) {
                    throw new Error("User not logged in");
                }
                return response.json();
            })
            .then(data => {
                if (data && data.firstName) {
                    nameEl.textContent = "NAME: " + String(data.firstName).toUpperCase();
                }
            })
            .catch(error => {
                console.log("User is browsing as Guest:", error);
            });
    }
}

function toggleButtons() {
    const clearBtn = document.getElementById("clear-list-btn");
    const downloadBtn = document.getElementById("download-list-btn");
    const listBody = document.getElementById("shopping-list-body");

    const isEmpty =
        !listBody ||
        listBody.children.length === 0 ||
        listBody.innerHTML.toLowerCase().includes("empty");

    if (clearBtn) {
        clearBtn.style.display = "inline-flex";
        clearBtn.disabled = isEmpty;
    }

    if (downloadBtn) {
        downloadBtn.style.display = "inline-flex";
        downloadBtn.disabled = isEmpty;
    }
}

function normalizeIngredientName(value) {
    return String(value || "")
        .toLowerCase()
        .replace(/[^\w\s-]/g, " ")
        .replace(/\s+/g, " ")
        .trim();
}

function hideAllBasketImages() {
    const allBasketImages = document.querySelectorAll(".basket-container .item");
    allBasketImages.forEach(function (img) {
        img.style.display = "none";
    });
}

function showBasketImageForIngredient(ingredientName) {
    const cleanName = normalizeIngredientName(ingredientName);
    if (!cleanName) return;

    BASKET_IMAGE_RULES.forEach(function (rule) {
        const matched = rule.keywords.some(function (keyword) {
            const cleanKeyword = normalizeIngredientName(keyword);
            return cleanName.includes(cleanKeyword);
        });

        if (matched) {
            const img = document.getElementById(rule.id);
            if (img) {
                img.style.display = "block";
            }
        }
    });
}

function updateBasketImages(items) {
    hideAllBasketImages();
    if (!items || items.length === 0) return;

    items.forEach(function (item) {
        showBasketImageForIngredient(item.name);
    });
}

function loadShoppingList() {
    const listBody = document.getElementById("shopping-list-body");
    if (!listBody) return;

    fetch('../ShoppingListController', { method: 'GET', credentials: 'same-origin' })
        .then(response => {
            if (!response.ok) {
                throw new Error("User not logged in or fetch failed");
            }
            return response.json();
        })
        .then(items => {
            if (items && items.length > 0) {
                renderShoppingList(items);
                updateBasketImages(items);
            } else {
                showEmptyShoppingList();
            }
            toggleButtons();
        })
        .catch(() => {
            const storedList = sessionStorage.getItem("guest_shopping_list");
            if (!storedList) {
                showEmptyShoppingList();
                return;
            }

            try {
                const items = JSON.parse(storedList);
                if (items && items.length > 0) {
                    renderShoppingList(items);
                    updateBasketImages(items);
                } else {
                    showEmptyShoppingList();
                }
            } catch (e) {
                showEmptyShoppingList();
            }
            toggleButtons();
        });
}

function renderShoppingList(items) {
    const listBody = document.getElementById("shopping-list-body");
    if (!listBody) return;

    listBody.innerHTML = "";

    items.forEach(function (item) {
        const row = document.createElement("tr");

        const quantity = item.quantity || 1;
        const name = item.name || "Unknown item";
        const unit = item.unit || item.amount || "";

        row.innerHTML = `
            <td class="begin">${escapeHTML(quantity)}</td>
            <td>${escapeHTML(name)}</td>
            <td class="length">${escapeHTML(unit)}</td>
        `;

        listBody.appendChild(row);
    });
}

function showEmptyShoppingList() {
    const listBody = document.getElementById("shopping-list-body");
    if (!listBody) return;

    listBody.innerHTML = `
        <tr>
            <td colspan="3" class="text-center">Your shopping list is empty.</td>
        </tr>
    `;

    hideAllBasketImages();
    toggleButtons();
}

function clearShoppingList() {
    fetch("../ShoppingListController", {
        method: "DELETE",
        credentials: "same-origin"
    })
        .then(function (response) {
            if (!response.ok) {
                throw new Error("Failed to clear list on the server.");
            }
            sessionStorage.removeItem("guest_shopping_list");
            showEmptyShoppingList();
            toggleButtons();
        })
        .catch(function (error) {
            console.warn("Backend clear failed. Clearing guest list only:", error);
            sessionStorage.removeItem("guest_shopping_list");
            showEmptyShoppingList();
            toggleButtons();
        });
}

function downloadShoppingList() {
    let items = [];
    
    const listBody = document.getElementById("shopping-list-body");
    if (listBody && !listBody.innerHTML.toLowerCase().includes("empty")) {
        const rows = listBody.querySelectorAll("tr");
        rows.forEach(row => {
            const cols = row.querySelectorAll("td");
            if (cols.length >= 3) {
                items.push({
                    quantity: cols[0].innerText,
                    name: cols[1].innerText,
                    unit: cols[2].innerText
                });
            }
        });
    }

    if (!items || items.length === 0) {
        alert("Your shopping list is empty.");
        return;
    }

    let text = "THE COOKBOOK - SHOPPING LIST\n";
    text += "--------------------------------\n\n";

    items.forEach(function (item) {
        const quantity = item.quantity || 1;
        const unit = item.unit || "";
        const name = item.name || "Unknown item";

        text += quantity + " " + unit + " " + name + "\n";
    });

    const blob = new Blob([text], { type: "text/plain" });
    const url = URL.createObjectURL(blob);

    const link = document.createElement("a");
    link.href = url;
    link.download = "shopping-list.txt";
    document.body.appendChild(link);
    link.click();
    document.body.removeChild(link);

    URL.revokeObjectURL(url);
}

function escapeHTML(value) {
    if (value === null || value === undefined) {
        return "";
    }

    return String(value)
        .replace(/&/g, "&amp;")
        .replace(/</g, "&lt;")
        .replace(/>/g, "&gt;")
        .replace(/"/g, "&quot;")
        .replace(/'/g, "&#039;");
}