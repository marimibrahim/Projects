class TreasureChest:
    #self.__question is private and declared as STRING
    #self.__answer is private and declared as INTEGER
    #self.__points is private and declared as INTEGER

    def __init__(self, question, answer, points):
        self.__question = question
        self.__answer = answer
        self.__points = points

    def getQuestion(self):
        return self.__question

    def checkAnswer(self, UserAnswer):
        if UserAnswer == int(self.__answer):
            return True
        else:
            return False

    def getPoints(self, Attempts):
        if Attempts == 1:
            return int(self.__points)
        elif Attempts == 2:
            return int(int(self.__points)/2)
        elif Attempts == 3 or Attempts == 4:
            return int(int(self.__points)/4)
        else:
            return 0

def readData():
    try:
        f = open("TreasureChestData.txt", "r")
        line = f.readline().strip()
        while line != "":
            question = line
            answer = f.readline().strip()
            points = f.readline().strip()
            arrayTreasure.append(TreasureChest(question, answer, points))
            line = f.readline().strip()
        f.close()
    except IOError:
        print("File not found")

arrayTreasure = []
readData()
Choice = int(input("Enter a question number between 1 and 5"))
while Choice < 1 or Choice > 5:
    print("Invalid choice")
    Choice = int(input("Enter a question number between 1 and 5"))
UserAnswer = int(input(arrayTreasure[Choice - 1].getQuestion()))
Result = arrayTreasure[Choice - 1].checkAnswer(UserAnswer)
Attempts = 1
while Result == False:
    print("Wrong answer")
    UserAnswer = int(input(arrayTreasure[Choice - 1].getQuestion()))
    Result = arrayTreasure[Choice - 1].checkAnswer(UserAnswer)
    Attempts = Attempts + 1
Points = arrayTreasure[Choice - 1].getPoints(Attempts)
print(Points)