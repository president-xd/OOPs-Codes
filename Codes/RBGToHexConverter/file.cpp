#include <iostream>
#include <string>

using namespace std;

// Function to convert an integer to a two-digit hex string
string intToHex(int value) {
    const char hexDigits[] = "0123456789abcdef";
    string hex;

    hex += hexDigits[(value >> 4) & 0xF];  // Get the high nibble
    hex += hexDigits[value & 0xF];         // Get the low nibble

    return hex;
}

// Function to convert RGB string to Hex color format
string rgbToHex(const string &rgb) {
    // Check if the input format is correct
    if (rgb.size() < 11 || rgb.substr(0, 4) != "rgb(" || rgb[rgb.size() - 1] != ')') {
        return "#000000"; // Return black if input is invalid
    }

    // Extract the RGB values manually
    int r = 0, g = 0, b = 0;
    int index = 4; // Starting index for RGB values
    char comma;

    // Parse red component
    while (index < rgb.size() && rgb[index] != ',') {
        r = r * 10 + (rgb[index] - '0');
        ++index;
    }
    ++index; // Skip the comma

    // Parse green component
    while (index < rgb.size() && rgb[index] != ',') {
        g = g * 10 + (rgb[index] - '0');
        ++index;
    }
    ++index; // Skip the comma

    // Parse blue component
    while (index < rgb.size() && rgb[index] != ')') {
        b = b * 10 + (rgb[index] - '0');
        ++index;
    }

    // Convert RGB to Hex
    return "#" + intToHex(r) + intToHex(g) + intToHex(b);
}

// Main function to test the rgbToHex function
int main() {
    cout << "Hex Color 1: " << rgbToHex("rgb(0, 128, 192)") << endl;
    cout << "Hex Color 2: " << rgbToHex("rgb(45, 255, 192)") << endl;
    cout << "Hex Color 3: " << rgbToHex("rgb(0, 0, 0)") << endl;
    cout << "Hex Color 4: " << rgbToHex("rgb(255, 255, 255)") << endl; // For testing white color
    cout << "Hex Color 5: " << rgbToHex("rgb(123, 234, 56)") << endl; // For testing another color

    return 0;
}
