databricks1.cpp
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function to format each paragraph based on alignment
vector<string> formatParagraph(const vector<string>& words, string alignment, int width) {
    vector<string> lines;
    stringstream lineStream;
    string line;
    int currentLength = 0;

    for (const string& word : words) {
        if (currentLength + word.length() + (currentLength > 0 ? 1 : 0) <= width) {
            if (currentLength > 0) lineStream << " ";
            lineStream << word;
            currentLength += word.length() + (currentLength > 0 ? 1 : 0);
        } else {
            line = lineStream.str();
            if (alignment == "RIGHT") {
                line = string(width - currentLength, ' ') + line;
            } else {
                line += string(width - currentLength, ' ');
            }
            lines.push_back(line);
            lineStream.str("");  // Reset stream
            lineStream.clear();
            lineStream << word;
            currentLength = word.length();
        }
    }

    // Add the last line
    line = lineStream.str();
    if (alignment == "RIGHT") {
        line = string(width - currentLength, ' ') + line;
    } else {
        line += string(width - currentLength, ' ');
    }
    lines.push_back(line);

    return lines;
}

// Function to wrap the formatted lines with border of asterisks
vector<string> solution(const vector<vector<string>>& paragraphs, const vector<string>& aligns, int width) {
    vector<string> result;
    string border(width + 2, '*');  // Top and bottom border

    result.push_back(border);  // Add top border

    for (int i = 0; i < paragraphs.size(); ++i) {
        vector<string> formattedLines = formatParagraph(paragraphs[i], aligns[i], width);
        for (const string& line : formattedLines) {
            result.push_back("*" + line + "*");  // Add side borders
        }
    }

    result.push_back(border);  // Add bottom border
    return result;
}

int main() {
    vector<vector<string>> paragraphs = {
        {"hello", "world"},
        {"How", "areYou", "doing"},
        {"Please", "look", "and", "align", "to", "right"}
    };
    vector<string> aligns = {"LEFT", "RIGHT", "RIGHT"};
    int width = 16;

    vector<string> result = solution(paragraphs, aligns, width);

    for (const string& line : result) {
        cout << line << endl;
    }

    return 0;
}
