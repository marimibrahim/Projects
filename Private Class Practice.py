class student:
    def __init__(self, name, dateOfBirth, examMark):
        self.__name = name
        self.__dateOfBirth = dateOfBirth
        self.__examMark = examMark
    def displayExamMark (self):
        print ("The student's name is: ", self.__name)
        print ("The student's mark is: ", self.__examMark)

myStudent1 = student("Fatima", "08/09/06", 20)
myStudent2 = student("Halima", "11/03/06", 25)
myStudent1.displayExamMark()
myStudent2.displayExamMark()
