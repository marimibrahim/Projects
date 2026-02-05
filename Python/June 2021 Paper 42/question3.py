class TreasureChest:
    #self.__question declared as STRING
    #self.__answer declared as INTEGER
    #self.__points declared as INTEGER
    def __init__(self, question, answer, points):
        self.__question = question
        self.__answer = answer
        self.__points = points

    def getQuestion(self):
        return self.__question

    def checkAnswer(self, UserAnswer):
        if UserAnswer == self.__answer:
            return True
        else:
            return False

    def getPoints(self, Attempts):
        if Attempts == 1:
            return self.__points
        elif Attempts == 2:
            return int(self.__points / 2)
        elif Attempts == 3 or Attempts == 4:
            return int(self.__points / 4)
        else:
            return 0

arrayTreasure = []
def readData():
    try:
        f = open("TreasureChestData.txt", "r")
        line = f.readline().strip()
        while line != "":
            question = line
            answer = int(f.readline().strip())
            points = int(f.readline().strip())
            arrayTreasure.append(TreasureChest(question, answer, points))
            line = f.readline().strip()
        f.close()
    except IOError:
        print("File not found")

readData()
Attempts = 1
UserChoice = int(input("Enter a number between 1 and 5"))
while UserChoice < 1 or UserChoice > 5:
    print("Invalid choice")
    UserChoice = int(input("Enter a number between 1 and 5"))
print(arrayTreasure[UserChoice - 1].getQuestion())
UserAnswer = int(input("Enter your answer"))
Result = arrayTreasure[UserChoice - 1].checkAnswer(UserAnswer)
if Result == False:
    print("Try again")
    UserAnswer = int(input("Enter your answer"))
    Attempts = Attempts + 1
UserPoints = arrayTreasure[UserChoice - 1].getPoints(Attempts)
print("Your points are", UserPoints)