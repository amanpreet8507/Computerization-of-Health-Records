//
//  HealthProfile.h
//  Computerization of Health Records
//
//  Created by Amanpreeet Sandhu on 2024-10-29.
//
#include <string>
#include <ctime>

class HealthProfile {
public:
    //constructor
    explicit HealthProfile(std::string fName, std::string lName, std::string gen, int m, int d, int y, double height, double weight): firstName{fName}, lastName{lName},gender{gen}, month{m}, day{d}, year{y}, heightInInches{height}, weightInPounds{weight}{};
    
    // Setters
    void setFirstName(std::string fName){
        firstName = fName;
    }
    
    void setLastName(std::string lName){
        lastName = lName;
    }
    
    void setMonth(int m) {
        month = m;
    }

    void setDay(int d) {
        day = d;
    }

    void setYear(int y) {
        year = y;
    }
    
    void setHeight(int height){
        heightInInches = height;
    }
    
    void setWeight(int weight){
        weightInPounds = weight;
    }
        
    // Getters
    std::string getFirstName() const {
        return firstName;
    }
    
    std::string getLastName() const {
        return lastName;
    }
    
    int getMonth() const {
        if (month > 12 || month < 1) {
            return 1;  // Default to 1 if month is invalid
        } else {
            return month;
        }
    }

    int getDay() const {
        return day;
    }

    int getYear() const {
        return year;
    }
    
    int getHeight() const {
        return heightInInches;
    }
    int getWeight() const {
        return weightInPounds;
    }
    
    // Member function to calculate person's age
    int calculateAge() const {
        // Get current year
        time_t t = time(0);
        tm* now = localtime(&t);
        int currentYear = now->tm_year + 1900;
        int age = currentYear-year;
        return age;
    }
    // Member function to calculate person's maximum heart rate
    int calculateMaxHeartRate() const {
        time_t t = time(0);
        tm* now = localtime(&t);
        int currentYear = now->tm_year + 1900;
        int age = currentYear-year;
        int maxHR = 220-age;
        return maxHR;
    }
    // Member function to calculate person's target heart rate
    std::string calculateTargetHeartRate() const{
        int maxHR = calculateMaxHeartRate();
        double targetLower = maxHR * 0.5;
        double targetUpper = maxHR * 0.85;
        return std::to_string(targetLower) + "-" + std::to_string(targetUpper) + " beats per minute";
    }
    // Member function to calculate bmi
    double calculateBMI() const {
        return (weightInPounds * 703) / (heightInInches * heightInInches);
    }
        
    // Member function for BMI category
    std::string getBMIcategory() const{
        double bmi = (weightInPounds * 703) / (heightInInches * heightInInches);
        if (bmi < 18.5) {
                return "Underweight: less than 18.5\n\n";
            } else if (bmi >= 18.5 && bmi <= 24.9){
                return "Normal : between 18.5 and 24.9\n\n";
            } else if (bmi >= 25 && bmi <= 29.9){
                return "Overweight : between 25 and 29.9\n\n";
            } else{
                return "Obese: 30 or greater\n\n";
            }
        }
    // Member function to display health profile
    void displayProfile() const{
        std::cout << "Name: " << firstName << " " << lastName << std::endl;
        std::cout << "Gender: " << gender << std::endl;
        std::cout << "Date of Birth: " << month << "/" << day << "/" << year << std::endl;
        std::cout << "Height (in inches): " << heightInInches << std::endl;
        std::cout << "Weight (in pounds): " << weightInPounds << std::endl;
        std::cout << "Age: " << calculateAge() << " years" << std::endl;
        std::cout << "BMI: " << calculateBMI() << " (" << getBMIcategory() << ")" << std::endl;
        std::cout << "Maximum Heart Rate: " << calculateMaxHeartRate() << " bpm" << std::endl << std::endl;
    }
private:
    std::string firstName;
    std::string lastName;
    std::string gender;
    int month;
    int day;
    int year;
    double heightInInches;
    double weightInPounds;
};
    
