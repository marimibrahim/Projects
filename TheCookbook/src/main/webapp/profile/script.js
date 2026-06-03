document.addEventListener("DOMContentLoaded", () => {
    const API_BASE = window.location.origin + "/TheCookbook";

    const logoutBtn = document.getElementById("logoutBtn");
    const profileToggleBtn = document.getElementById("profileToggleBtn");
	const fileInput = document.getElementById("file-input");
	const profilePicture = document.querySelector(".profile-picture");
	const topAvatar = document.querySelector(".avatar");
    const fields = ["first-name", "last-name", "username", "email", "password"];

    if (window.location.pathname.includes("profile.html")) {
        loadUserDetails();
        loadSavedRecipes();
    }

    function loadUserDetails() {
        fetch(API_BASE + "/ProfileController", {
            method: "GET",
            credentials: "same-origin",
            cache: "no-store"
        })
            .then(response => {
                if (response.status === 401) {
                    window.location.href = API_BASE + "/profile/login.html";
                    return null;
                }

                if (!response.ok) {
                    throw new Error("Could not load user details.");
                }

                return response.json();
            })
            .then(data => {
                if (!data) return;

                const firstNameInput = document.getElementById("first-name");
                const lastNameInput = document.getElementById("last-name");
                const usernameInput = document.getElementById("username");
                const emailInput = document.getElementById("email");
                const welcomeText = document.getElementById("welcome-text");

                if (firstNameInput) firstNameInput.value = data.firstName || "";
                if (lastNameInput) lastNameInput.value = data.lastName || "";
                if (usernameInput) usernameInput.value = data.username || "";
                if (emailInput) emailInput.value = data.email || "";

                if (welcomeText) {
                    welcomeText.textContent =
                        "Welcome, " + (data.firstName || data.username || "User") + "!";
                }
            })
            .catch(error => {
                console.error("Error fetching user details:", error);
                window.location.href = API_BASE + "/profile/login.html";
            });
    }

    function loadSavedRecipes() {
        const favoritesGrid = document.getElementById("favoritesGrid");

        if (!favoritesGrid) {
            console.error("favoritesGrid not found in profile.html");
            return;
        }

        fetch(API_BASE + "/GetSavedRecipesServlet", {
            method: "GET",
            credentials: "same-origin",
            cache: "no-store"
        })
            .then(response => {
                if (response.status === 401) {
                    favoritesGrid.innerHTML = `
                        <div class="col-12">
                            <p class="text-center">Please log in to view saved recipes.</p>
                        </div>
                    `;
                    return null;
                }

                if (!response.ok) {
                    throw new Error("Could not load saved recipes.");
                }

                return response.json();
            })
            .then(recipes => {
                if (!recipes) return;
                renderSavedRecipes(recipes);
            })
            .catch(error => {
                console.error("Error loading saved recipes:", error);
                favoritesGrid.innerHTML = `
                    <div class="col-12">
                        <p class="text-center">Could not load saved recipes.</p>
                    </div>
                `;
            });
    }

    function renderSavedRecipes(recipes) {
        const favoritesGrid = document.getElementById("favoritesGrid");

        if (!favoritesGrid) {
            return;
        }

        if (!recipes || recipes.length === 0) {
            favoritesGrid.innerHTML = `
                <div class="col-12">
                    <p class="text-center">You have not saved any recipes yet.</p>
                </div>
            `;
            return;
        }

        favoritesGrid.innerHTML = "";

        recipes.forEach(recipe => {
            const recipeId = recipe.recipeId;
            const recipeName = recipe.recipeName || "Untitled Recipe";
            const prepTime = recipe.prepTime || recipe.totalTime || "Not specified";
            const rating = recipe.rating || "N/A";
            const servings = recipe.servings || "N/A";
            const imagePath = getRecipeImagePath(recipe.imgSrc || recipe.imagePath);

            const card = document.createElement("div");
            card.className = "col-12 col-sm-6 col-lg-3";

            card.innerHTML = `
                <div class="recipe-card h-100 shadow-sm saved-recipe-card" data-recipe-id="${recipeId}">
                    <div class="card-img-placeholder position-relative">
                        <img src="${imagePath}" alt="${escapeHtml(recipeName)}" class="saved-recipe-img">
                        <span class="lemon-icon position-absolute top-0 end-0 m-2">🍋</span>
                    </div>

                    <div class="card-info p-3">
                        <h3 class="dark-blue-text h5">${escapeHtml(recipeName)}</h3>
                        <p class="text-muted small mb-1">Prep: ${escapeHtml(prepTime)}</p>
                        <p class="text-muted small mb-1">Rating: ${escapeHtml(rating)}</p>
                        <span class="badge bg-light text-dark border border-dark">
                            Serves ${escapeHtml(servings)}
                        </span>
                    </div>
                </div>
            `;

            const savedCard = card.querySelector(".saved-recipe-card");

            if (savedCard) {
                savedCard.addEventListener("click", () => {
                    window.location.href = `../recipes/recipe.html?recipeId=${recipeId}`;
                });
            }

            favoritesGrid.appendChild(card);
        });
    }

	function getRecipeImagePath(imagePath) {
	    if (!imagePath) {
	        return "../home/recipe_images/default.jpg";
	    }

	    if (imagePath.startsWith("http://") || imagePath.startsWith("https://")) {
	        return imagePath;
	    }

	    if (imagePath.startsWith("../home/")) {
	        return imagePath;
	    }

	    if (imagePath.startsWith("home/")) {
	        return "../" + imagePath;
	    }

	    if (imagePath.startsWith("recipe_images/")) {
	        return "../home/" + imagePath;
	    }

	    return "../home/recipe_images/" + imagePath;
	}

    function escapeHtml(value) {
        return String(value || "")
            .replace(/&/g, "&amp;")
            .replace(/</g, "&lt;")
            .replace(/>/g, "&gt;")
            .replace(/"/g, "&quot;")
            .replace(/'/g, "&#039;");
    }

    if (logoutBtn) {
        logoutBtn.addEventListener("click", () => {
            window.location.href = API_BASE + "/LogoutServlet";
        });
    }

	const savedProfileImage = localStorage.getItem("cookbook_profile_picture");

	if (savedProfileImage) {
	    if (profilePicture) profilePicture.src = savedProfileImage;
	    if (topAvatar) topAvatar.src = savedProfileImage;
	}

	if (fileInput) {
	    fileInput.addEventListener("change", function () {
	        const file = this.files[0];

	        if (!file) {
	            return;
	        }

	        if (!file.type.startsWith("image/")) {
	            alert("Please select an image file.");
	            return;
	        }

	        const reader = new FileReader();

	        reader.onload = function (event) {
	            const imageData = event.target.result;

	            if (profilePicture) {
	                profilePicture.src = imageData;
	            }

	            if (topAvatar) {
	                topAvatar.src = imageData;
	            }

	            localStorage.setItem("cookbook_profile_picture", imageData);
	        };

	        reader.readAsDataURL(file);
	    });
	}

    if (profileToggleBtn) {
        profileToggleBtn.addEventListener("click", function () {
            const isEditing = this.textContent.trim() === "Save Changes";

            if (!isEditing) {
                fields.forEach(id => {
                    const input = document.getElementById(id);
                    if (input) input.disabled = false;
                });

                this.textContent = "Save Changes";
                this.classList.add("save-active");
            } else {
                const updatedData = {
                    firstName: document.getElementById("first-name")?.value || "",
                    lastName: document.getElementById("last-name")?.value || "",
                    username: document.getElementById("username")?.value || "",
                    email: document.getElementById("email")?.value || ""
                };

                fetch(API_BASE + "/ProfileController", {
                    method: "POST",
                    credentials: "same-origin",
                    cache: "no-store",
                    headers: {
                        "Content-Type": "application/json"
                    },
                    body: JSON.stringify(updatedData)
                })
                    .then(response => {
                        if (response.status === 401) {
                            alert("Your session expired. Please log in again.");
                            window.location.href = API_BASE + "/profile/login.html";
                            return null;
                        }

                        if (!response.ok) {
                            throw new Error("Profile update failed.");
                        }

                        alert("Profile Updated!");

                        fields.forEach(id => {
                            const input = document.getElementById(id);
                            if (input) input.disabled = true;
                        });

                        this.textContent = "Edit Profile";
                        this.classList.remove("save-active");

                        loadUserDetails();
                    })
                    .catch(error => {
                        console.error("Error updating profile:", error);
                        alert("Could not update profile.");
                    });
            }
        });
    }
});

function openTab(tabName, event) {
    const tabContents = document.getElementsByClassName("tab-content");

    for (let i = 0; i < tabContents.length; i++) {
        tabContents[i].style.display = "none";
        tabContents[i].classList.remove("active-content");
    }

    const tabBtns = document.getElementsByClassName("tab-btn");

    for (let i = 0; i < tabBtns.length; i++) {
        tabBtns[i].classList.remove("active");
    }

    const selectedTab = document.getElementById(tabName);

    if (selectedTab) {
        selectedTab.style.display = "block";
        selectedTab.classList.add("active-content");
    }

    if (event && event.currentTarget) {
        event.currentTarget.classList.add("active");
    }
	
	const profileScreen = document.getElementById("profileScreen");

	if (profileScreen) {
	    if (tabName === "settings") {
	        profileScreen.classList.add("settings-mode");
	    } else {
	        profileScreen.classList.remove("settings-mode");
	    }
	}
}