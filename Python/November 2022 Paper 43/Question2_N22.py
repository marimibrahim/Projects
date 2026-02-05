class Card:
    #self.__Number is private and INTEGER
    #self.__Colour is private and STRING
    def __init__(self, Number, Colour):
        self.__Number = Number
        self.__Colour = Colour

    def GetNumber(self):
        return self.__Number

    def GetColour(self):
        return self.__Colour

class Hand:
    #Cards is an ARRAY of type Card
    #FirstCard is INTEGER and initialised to 0
    #NumberCards is INTEGER and initialised to 5
    def __init__(self, Card1, Card2, Card3, Card4, Card5):
        self.Cards = []
        self.Cards.append(Card1)
        self.Cards.append(Card2)
        self.Cards.append(Card3)
        self.Cards.append(Card4)
        self.Cards.append(Card5)
        self.FirstCard = 0
        self.NumberCards = 5

    def GetCard(self, Index):
        return self.Cards[Index]

RedCard1 = Card(1, "red")
RedCard2 = Card(2, "red")
RedCard3 = Card(3, "red")
RedCard4 = Card(4, "red")
RedCard5 = Card(5, "red")
BlueCard1 = Card(1, "blue")
BlueCard2 = Card(2, "blue")
BlueCard3 = Card(3, "blue")
BlueCard4 = Card(4, "blue")
BlueCard5 = Card(5, "blue")
YellowCard1 = Card(1, "yellow")
YellowCard2 = Card(2, "yellow")
YellowCard3 = Card(3, "yellow")
YellowCard4 = Card(4, "yellow")
YellowCard5 = Card(5, "yellow")

Player1 = Hand(RedCard1, RedCard2, RedCard3, RedCard4, YellowCard1)
Player2 = Hand(YellowCard2, YellowCard3, YellowCard4, YellowCard5, BlueCard1)

def CalculateValue(PlayerHand):
    Score = 0
    for i in range(5):
        Card = PlayerHand.GetCard(i)
        Score = Score + Card.GetNumber()
        CardColour = Card.GetColour().lower()
        if CardColour == "red":
            Score = Score + 5
        elif CardColour == "blue":
            Score = Score + 10
        elif CardColour == "yellow":
            Score = Score + 15
    return Score

Score1 = CalculateValue(Player1)
Score2 = CalculateValue(Player2)

print(Score1)
print(Score2)

if Score1 > Score2:
    print("Player 1 won")
elif Score2 > Score1:
    print("Player 2 won")
else:
    print("Draw")