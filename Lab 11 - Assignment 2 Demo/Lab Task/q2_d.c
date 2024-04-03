void GradeBook::displayMessage() {
    std::cout << "Welcome to the course: " << courseName << std::endl;
    std::cout << "This course is presented by: " << lecturerName << std::endl;
}

int main() {
    GradeBook gradeBook("Developing Technical Software", "Nalin Randeniya");

    gradeBook.displayMessage();

    gradeBook.setLecturerName("Nalin Randeniya");
    std::cout << "Updated lecturer's name: " << gradeBook.getLecturerName() << std::endl;

    return 0;
}