#include <stdio.h>
#include <stdlib.h>

// Function to apply zero-padding
void apply_padding(int *input, int *padded, int size, int window_size){
    int pad = (window_size - 1) / 2;
    for (int i = 0; i < pad; i++)
    {
        padded[i] = 0;              // Zero padding at the start
        padded[size + pad + i] = 0; // Zero padding at the end
    }
    for (int i = 0; i < size; i++)
    {
        padded[pad + i] = input[i];
    }
}

// Helper function to calculate median
int calculate_median(int *window, int window_size){
    int temp[window_size];
    for (int i = 0; i < window_size; i++)
    {
        temp[i] = window[i];
    }
    // Sort the temporary array
    for (int i = 0; i < window_size - 1; i++)
    {
        for (int j = i + 1; j < window_size; j++)
        {
            if (temp[i] > temp[j])
            {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
    return temp[window_size / 2];
}

// Function for maximum filter
void max_filter(int *window, int window_size, int *output){
    *output = window[0];
    for (int k = 1; k < window_size; k++)
    {
        if (window[k] > *output)
        {
            *output = window[k];
        }
    }
}

// Function for minimum filter
void min_filter(int *window, int window_size, int *output){
    *output = window[0];
    for (int k = 1; k < window_size; k++)
    {
        if (window[k] < *output)
        {
            *output = window[k];
        }
    }
}

// Function for median filter
void median_filter(int *window, int window_size, int *output){
    *output = calculate_median(window, window_size);
}

// Function for average filter
void average_filter(int *window, int window_size, float *output){
    *output = 0;
    for (int k = 0; k < window_size; k++){
        *output += window[k];
    }
    *output /= window_size;
}

// Sliding window filter functions
void sliding_window_filter(int *input, int size, int window_size, void *output, char type){
    int pad = (window_size - 1) / 2;
    int padded_size = size + 2 * pad;
    int padded[padded_size];

    apply_padding(input, padded, size, window_size);

    for (int i = 0; i < size; i++){
        int window[window_size];
        for (int j = 0; j < window_size; j++){
            window[j] = padded[i + j];
        }

        if (type == 'M')
        { // Maximum filter
            max_filter(window, window_size, &((int *)output)[i]);
        }
        else if (type == 'm')
        { // Minimum filter
            min_filter(window, window_size, &((int *)output)[i]);
        }
        else if (type == 'd')
        { // Median filter
            median_filter(window, window_size, &((int *)output)[i]);
        }
        else if (type == 'a')
        { // Average filter
            average_filter(window, window_size, &((float *)output)[i]);
        }
        else
        {
            printf("Unknown filter type\n");
            return;
        }
    }
}

int main()
{
    int input[] = {4, 5, 1, 13, 3, 25, 27, 18, 10, 3, 4, 9};
    int size = sizeof(input) / sizeof(input[0]);
    int window_size = 3;

    int output[size];
    float avg_output[size];

    // Max filter
    sliding_window_filter(input, size, window_size, output, 'M');
    printf("Max filter output: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", output[i]);
    }
    printf("\n");

    // Min filter
    sliding_window_filter(input, size, window_size, output, 'm');
    printf("Min filter output: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", output[i]);
    }
    printf("\n");

    // Median filter
    sliding_window_filter(input, size, window_size, output, 'd');
    printf("Median filter output: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", output[i]);
    }
    printf("\n");

    // Average filter
    sliding_window_filter(input, size, window_size, avg_output, 'a');
    printf("Average filter output: ");
    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", avg_output[i]);
    }
    printf("\n");

    return 0;
}