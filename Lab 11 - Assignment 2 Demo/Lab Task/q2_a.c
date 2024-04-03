#include <iostream>
#include <string>

class GradeBook {
public:
    GradeBook(std::string courseName, std::string lecturerName); // Constructor

    // Set function to change the lecturer's name
    void setLecturerName(std::string lecturerName);

    // Get function to retrieve the lecturer's name
    std::string getLecturerName();

    // Function to display the welcome message, course name, and lecturer's name
    void displayMessage();

private:
    std::string courseName;
    std::string lecturerName; // New data member for lecturer's name
};
