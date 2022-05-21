#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>

int find_next_max_piece_index(int n, const double* const lengths, const int* const piece_usage);
double find_max_piece(int n, int k, const double* const lengths);
char* task(int n, int k, const double* const lengths);

// length might be up to 100 000 000
double find_max_piece(int n, int k, const double* const lengths) {
    // How many times we use each piece
    int* piece_usage = new int[n];
    
    for (int i = 0; i < n; i++) {
        piece_usage[i] = 0;
    }
    
    int pieces_count = 0;
    int next_piece_index = -1;
    double min_piece_length = 0;
    
    while(pieces_count != k) {
        next_piece_index = find_next_max_piece_index(n, lengths, piece_usage);
        piece_usage[next_piece_index]++;
        min_piece_length = lengths[next_piece_index] / piece_usage[next_piece_index];
        
        pieces_count++;
    }
    
    return min_piece_length;
}

// Returns index of next piece
int find_next_max_piece_index(int n, const double* const lengths, const int* const piece_usage) {
    int max_piece_index = 0;
    double max_piece_length = lengths[0] / (piece_usage[0] + 1);
    double current_piece_length = lengths[0] / (piece_usage[0] + 1);
    
    for (int i = 1; i < n; i++) {
        current_piece_length = lengths[i] / (piece_usage[i] + 1);
        if (current_piece_length > max_piece_length) {
            max_piece_index = i;
            max_piece_length = current_piece_length;
        }
    }
    
    return max_piece_index;
}

char* task(int n, int k, const double* const lengths) {
    double max_piece_length = find_max_piece(n, k, lengths);
    double piece_fixed_precision = std::trunc(max_piece_length * 100) / 100;
    char* formatted_string = new char[256];
    formatted_string[255] = '\0';
    std::sprintf(formatted_string, "%.2lf\n", piece_fixed_precision);
    return formatted_string;
}

int main() {
    int N = 0;
    int K = 0;

    std::cin >> N >> K;
    
    double* lengths = new double[N];

    for (int i = 0; i < N; i++) {
        std::cin >> lengths[i];
    }

    char* task_output = task(N, K, lengths);
    std::cout << task_output << '\n';


    delete[] task_output;
    delete[] lengths;
}
