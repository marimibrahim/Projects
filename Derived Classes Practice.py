class student:
    def __init__(self, name, mark):
        self.__name = name
        self.__mark = mark
    def displayExamMark(self):
        print("The student's name is: ", self.__name)
        print("The student's mark is: ", self.__mark)
class fullTimeStudent:
    def __init__(self, name, mark):
        student.__init__(self, name, mark)
    def displayExamMark(self):
        print("The information about the full-time student: ")
        student.displayExamMark(self)
class partTimeStudent:
    def __init__(self, name, mark):
        student.__init__(self, name, mark)
    def displayExamMark(self):
        print("The information about the part-time student: ")
        student.displayExamMark(self)
        
student1 = fullTimeStudent("Mariam", 20)
student1.displayExamMark()
student2 = partTimeStudent("Sara", 15)
student2.displayExamMark()

