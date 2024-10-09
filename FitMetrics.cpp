#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <fstream>

using namespace std;

string toLowerCase(string str) {
    for(auto &c : str) {
        c = tolower(c);
    }
    return str;
}

int getValidatedInput(const string& prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if(cin.fail() || value < min || value > max) {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

float getValidatedFloat(const string& prompt, float min, float max) {
    float value;
    while (true) {
        cout << prompt;
        cin >> value;

        if(cin.fail() || value < min || value > max) {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

string getValidatedString(const string& prompt, const string& option1, const string& option2) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        string lowered = toLowerCase(input);
        if(lowered == toLowerCase(option1) || lowered == toLowerCase(option2)) {
            return lowered;
        } else {
            cout << "Invalid input. Please enter \"" << option1 << "\" or \"" << option2 << "\"." << endl;
        }
    }
}

int main() {
    float age, weight, height, bmi, bmr, calories;
    float protein_calories, fat_calories, carb_calories;
    float protein_grams, fat_grams, carb_grams;
    string gender;
    int activity_level;

    cout << "BMI and BMR Calculator with Daily Calorie Needs" << endl;
    cout << "---------------------------------------------" << endl;

    age = getValidatedFloat("Enter your age (years): ", 10, 120);
    weight = getValidatedFloat("Enter your weight (kg): ", 20, 500);
    height = getValidatedFloat("Enter your height (cm): ", 50, 300);
    gender = getValidatedString("Enter your gender (male / female): ", "male", "female");

    cout << "Choose your activity level:" << endl;
    cout << "1. Sedentary (little or no exercise)" << endl;
    cout << "2. Light (light exercise/sports 1-3 days/week)" << endl;
    cout << "3. Moderate (moderate exercise/sports 3-5 days/week)" << endl;
    cout << "4. High (hard exercise/sports 6-7 days a week)" << endl;
    cout << "5. Very High (very hard exercise/sports & physical job or training twice a day)" << endl;
    activity_level = getValidatedInput("Choose a level number (1-5): ", 1, 5);

    bmi = weight / ((height / 100) * (height / 100));

    if (gender == toLowerCase("male")) {
        bmr = 10 * weight + 6.25 * height - 5 * age + 5;
    } else {
        bmr = 10 * weight + 6.25 * height - 5 * age - 161;
    }

    switch (activity_level) {
        case 1:
            calories = bmr * 1.2;
            break;
        case 2:
            calories = bmr * 1.375;
            break;
        case 3:
            calories = bmr * 1.55;
            break;
        case 4:
            calories = bmr * 1.725;
            break;
        case 5:
            calories = bmr * 1.9;
            break;
        default:
            calories = bmr * 1.2;
            break;
    }

    if (bmi < 18.5) {
        cout << "You are underweight. Increasing daily calories by 500." << endl;
        calories += 500;
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        cout << "You have a normal weight. No changes." << endl;
    } else if (bmi >= 25 && bmi <= 29.9) {
        cout << "You are overweight. Reducing daily calories by 500." << endl;
        calories -= 500;
    } else if (bmi >= 30 && bmi <= 39.9) {
        cout << "You are obese. Reducing daily calories by 500." << endl;
        calories -= 500;
    } else {
        cout << "You are extremely obese. Reducing daily calories by 1500." << endl;
        calories -= 1500;
    }

    if(calories < 1200){
        cout << "Adjusted daily calories to the minimum healthy limit (1200 kcal)." << endl;
        calories = 1200;
    }

    protein_calories = calories * 0.20;
    fat_calories = calories * 0.25;
    carb_calories = calories * 0.55;

    protein_grams = protein_calories / 4;
    fat_grams = fat_calories / 9;
    carb_grams = carb_calories / 4;

    cout << "\n===== Results =====" << endl;
    cout << "Your BMI is: " << bmi << endl;
    cout << "Your daily calorie needs: " << calories << " kcal" << endl;
    cout << "You should consume:" << endl;
    cout << "- " << protein_grams << " grams of protein" << endl;
    cout << "- " << fat_grams << " grams of fat" << endl;
    cout << "- " << carb_grams << " grams of carbohydrates" << endl;

    cout << "\n===== Personalized Advice =====" << endl;
    if (bmi < 18.5) {
        cout << "• You are underweight. Consider consulting with a healthcare provider to develop a plan to gain weight safely." << endl;
        cout << "• Increase your calorie intake with nutrient-dense foods." << endl;
        cout << "• Incorporate strength training exercises to build muscle mass." << endl;
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        cout << "• You have a healthy weight. Maintain your current lifestyle to keep your weight stable." << endl;
        cout << "• Continue eating a balanced diet rich in fruits, vegetables, lean proteins, and whole grains." << endl;
        cout << "• Stay active with regular physical activity." << endl;
    } else if (bmi >= 25 && bmi <= 29.9) {
        cout << "• You are overweight. Consider adopting a calorie-controlled diet and increasing physical activity." << endl;
        cout << "• Incorporate more fruits, vegetables, and lean proteins into your meals." << endl;
        cout << "• Aim for at least 150 minutes of moderate-intensity exercise per week." << endl;
    } else if (bmi >= 30 && bmi <= 39.9) {
        cout << "• You are obese. It's important to consult with a healthcare provider for personalized advice." << endl;
        cout << "• Focus on a balanced, reduced-calorie diet and increase physical activity." << endl;
        cout << "• Consider incorporating both cardio and strength training exercises into your routine." << endl;
    } else {
        cout << "• You are extremely obese. Immediate medical attention is recommended." << endl;
        cout << "• Work with healthcare professionals to develop a comprehensive weight loss plan." << endl;
        cout << "• Focus on significant dietary changes and structured physical activity programs." << endl;
    }

    cout << "\n===== Activity Level Advice =====" << endl;
    switch(activity_level) {
        case 1:
            cout << "• Sedentary: Try to incorporate regular physical activity into your daily routine." << endl;
            cout << "• Aim for at least 150 minutes of moderate-intensity exercise per week." << endl;
            cout << "• Simple activities like walking, cycling, or swimming can make a significant difference." << endl;
            break;
        case 2:
            cout << "• Light: Great job maintaining an active lifestyle!" << endl;
            cout << "• Consider increasing the frequency or intensity of your workouts for additional benefits." << endl;
            cout << "• Incorporate strength training to build muscle mass." << endl;
            break;
        case 3:
            cout << "• Moderate: You have a balanced activity level." << endl;
            cout << "• Continue with your current routine to maintain your fitness and health." << endl;
            cout << "• Adding variety to your workouts can help prevent plateaus and keep you motivated." << endl;
            break;
        case 4:
            cout << "• High: You are highly active. Ensure you are getting adequate rest and recovery." << endl;
            cout << "• Incorporate stretching and flexibility exercises to prevent injuries." << endl;
            cout << "• Monitor your nutrition to support your high activity levels." << endl;
            break;
        case 5:
            cout << "• Very High: You engage in very intense physical activity." << endl;
            cout << "• Consider consulting with a fitness professional to optimize your training regimen." << endl;
            cout << "• Ensure you are meeting your nutritional needs to support your activity level." << endl;
            cout << "• Prioritize rest and recovery to prevent overtraining and injuries." << endl;
            break;
        default:
            cout << "• Unknown activity level." << endl;
            break;
    }

    // Generate Report
    ofstream reportFile("report.txt");
    if(reportFile.is_open()) {
        reportFile << "BMI and BMR Calculator Report" << endl;
        reportFile << "=============================" << endl << endl;

        reportFile << "User Details:" << endl;
        reportFile << "Age: " << age << " years" << endl;
        reportFile << "Weight: " << weight << " kg" << endl;
        reportFile << "Height: " << height << " cm" << endl;
        reportFile << "Gender: " << (gender == "male" ? "Male" : "Female") << endl;
        reportFile << "Activity Level: " << activity_level << endl << endl;

        reportFile << "Calculated Metrics:" << endl;
        reportFile << "BMI: " << bmi << endl;
        reportFile << "BMR: " << bmr << " kcal/day" << endl;
        reportFile << "Daily Calorie Needs: " << calories << " kcal" << endl << endl;

        reportFile << "Macronutrient Breakdown:" << endl;
        reportFile << "Protein: " << protein_grams << " grams" << endl;
        reportFile << "Fat: " << fat_grams << " grams" << endl;
        reportFile << "Carbohydrates: " << carb_grams << " grams" << endl << endl;

        reportFile << "Personalized Advice:" << endl;
        if (bmi < 18.5) {
            reportFile << "• You are underweight. Consider consulting with a healthcare provider to develop a plan to gain weight safely." << endl;
            reportFile << "• Increase your calorie intake with nutrient-dense foods." << endl;
            reportFile << "• Incorporate strength training exercises to build muscle mass." << endl;
        } else if (bmi >= 18.5 && bmi <= 24.9) {
            reportFile << "• You have a healthy weight. Maintain your current lifestyle to keep your weight stable." << endl;
            reportFile << "• Continue eating a balanced diet rich in fruits, vegetables, lean proteins, and whole grains." << endl;
            reportFile << "• Stay active with regular physical activity." << endl;
        } else if (bmi >= 25 && bmi <= 29.9) {
            reportFile << "• You are overweight. Consider adopting a calorie-controlled diet and increasing physical activity." << endl;
            reportFile << "• Incorporate more fruits, vegetables, and lean proteins into your meals." << endl;
            reportFile << "• Aim for at least 150 minutes of moderate-intensity exercise per week." << endl;
        } else if (bmi >= 30 && bmi <= 39.9) {
            reportFile << "• You are obese. It's important to consult with a healthcare provider for personalized advice." << endl;
            reportFile << "• Focus on a balanced, reduced-calorie diet and increase physical activity." << endl;
            reportFile << "• Consider incorporating both cardio and strength training exercises into your routine." << endl;
        } else {
            reportFile << "• You are extremely obese. Immediate medical attention is recommended." << endl;
            reportFile << "• Work with healthcare professionals to develop a comprehensive weight loss plan." << endl;
            reportFile << "• Focus on significant dietary changes and structured physical activity programs." << endl;
        }

        reportFile << "\nActivity Level Advice:" << endl;
        switch(activity_level) {
            case 1:
                reportFile << "• Sedentary: Try to incorporate regular physical activity into your daily routine." << endl;
                reportFile << "• Aim for at least 150 minutes of moderate-intensity exercise per week." << endl;
                reportFile << "• Simple activities like walking, cycling, or swimming can make a significant difference." << endl;
                break;
            case 2:
                reportFile << "• Light: Great job maintaining an active lifestyle!" << endl;
                reportFile << "• Consider increasing the frequency or intensity of your workouts for additional benefits." << endl;
                reportFile << "• Incorporate strength training to build muscle mass." << endl;
                break;
            case 3:
                reportFile << "• Moderate: You have a balanced activity level." << endl;
                reportFile << "• Continue with your current routine to maintain your fitness and health." << endl;
                reportFile << "• Adding variety to your workouts can help prevent plateaus and keep you motivated." << endl;
                break;
            case 4:
                reportFile << "• High: You are highly active. Ensure you are getting adequate rest and recovery." << endl;
                reportFile << "• Incorporate stretching and flexibility exercises to prevent injuries." << endl;
                reportFile << "• Monitor your nutrition to support your high activity levels." << endl;
                break;
            case 5:
                reportFile << "• Very High: You engage in very intense physical activity." << endl;
                reportFile << "• Consider consulting with a fitness professional to optimize your training regimen." << endl;
                reportFile << "• Ensure you are meeting your nutritional needs to support your activity level." << endl;
                reportFile << "• Prioritize rest and recovery to prevent overtraining and injuries." << endl;
                break;
            default:
                reportFile << "• Unknown activity level." << endl;
                break;
        }

        reportFile.close();
        cout << "\nReport has been successfully saved to 'report.txt'." << endl;
    } else {
        cout << "Unable to create report file." << endl;
    }

    return 0;
}
