#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILES 6
#define MAX_KEYWORDS 10
#define MAX_LINE_LENGTH 512
#define MAX_KEYWORD_LENGTH 50

// Structure for storing occurrences of a keyword in a file
typedef struct {
    char filename[MAX_KEYWORD_LENGTH];
    int count;
} FileOccurrence;

// Structure for storing keyword occurrences across files
typedef struct {
    char keyword[MAX_KEYWORD_LENGTH];
    FileOccurrence fileOccurrences[MAX_FILES];
} KeywordIndex;

// Check if a character is a word boundary
int isWordBoundary(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '.' || ch == ',' || ch == ';' || ch == '!' || ch == '?';
}

// Count occurrences of keyword in a line (case-insensitive, whole word only)
int countOccurrences(char* line, const char* keyword) {
    int count = 0;
    int lineLength = strlen(line);
    int keywordLength = strlen(keyword);

    // Convert keyword to lowercase for case-insensitive comparison
    char keywordLower[MAX_KEYWORD_LENGTH];
    for (int i = 0; i < keywordLength; i++) {
        keywordLower[i] = tolower((unsigned char)keyword[i]);
    }
    keywordLower[keywordLength] = '\0';  // Null-terminate

    for (int i = 0; i <= lineLength - keywordLength; i++) {
        // Extract a substring and convert to lowercase
        char linePart[MAX_KEYWORD_LENGTH];
        strncpy(linePart, &line[i], keywordLength);
        linePart[keywordLength] = '\0';  // Null terminate

        // Convert the substring to lowercase
        for (int j = 0; linePart[j]; j++) {
            linePart[j] = tolower((unsigned char)linePart[j]);
        }

        // Check if it's a match and ensure it's surrounded by word boundaries
        if (strncmp(linePart, keywordLower, keywordLength) == 0) {
            // Ensure the character before the match is a word boundary or the start of the line
            if ((i == 0 || isWordBoundary(line[i - 1])) && (i + keywordLength == lineLength || isWordBoundary(line[i + keywordLength]))) {
                count++;
            }
        }
    }

    return count;
}

// Function to find frequency of each keyword
void createInvertedIndex(const char** files, int num_files, const char** keywords, int num_keywords, KeywordIndex* keyword_occurences) {
    for (int i = 0; i < num_keywords; i++) {
        strcpy(keyword_occurences[i].keyword, keywords[i]);

        // Initialize the count to zero for all files
        for (int j = 0; j < num_files; j++) {
            strcpy(keyword_occurences[i].fileOccurrences[j].filename, files[j]);
            keyword_occurences[i].fileOccurrences[j].count = 0;
        }

        // Process each file
        for (int j = 0; j < num_files; j++) {
            FILE* fp = fopen(files[j], "r");
            if (fp == NULL) {
                perror("Error opening file");
                continue;
            }

            char line[MAX_LINE_LENGTH];
            int count = 0;

            // Read lines in the file and count occurrences of the keyword
            while (fgets(line, sizeof(line), fp)) {
                count += countOccurrences(line, keywords[i]);
            }

            // Update the count for the keyword in the current file
            keyword_occurences[i].fileOccurrences[j].count = count;

            fclose(fp);
        }
    }
}

// Function to make Inverted Index File
void makeInvertedIndexFile(KeywordIndex *keyword_occurences, int numKeywords) {
    FILE* fp = fopen("InvertedIndex.txt", "w");
    if (fp == NULL) {
        perror("Error opening InvertedIndex.txt");
        return;
    }

    for (int i = 0; i < numKeywords; i++) {
        fprintf(fp, "Keyword: %s\n", keyword_occurences[i].keyword);
        for (int j = 0; j < MAX_FILES; j++) {
            fprintf(fp, "  FileName: %s | Occurrences: %d\n", keyword_occurences[i].fileOccurrences[j].filename, keyword_occurences[i].fileOccurrences[j].count);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main() {
    const char *files[MAX_FILES] = {"Files/file1.txt", "Files/file2.txt", "Files/file3.txt", "Files/file4.txt", "Files/file5.txt", "Files/file6.txt"};

    int word_count = 6;
    const char *keywords[MAX_KEYWORDS] = {"fox", "dog", "quick", "lazy", "food", "book"};

    KeywordIndex keyword_occurences[MAX_KEYWORDS];
    createInvertedIndex(files, MAX_FILES, keywords, word_count, keyword_occurences);
    makeInvertedIndexFile(keyword_occurences, word_count);

    printf("Inverted index has been written to 'InvertedIndex.txt'.\n");

    return 0;
}
