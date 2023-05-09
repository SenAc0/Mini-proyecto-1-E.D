#include "ListArray.h" 
#include <chrono> 
using namespace std; 
 
int main() { 
    int sizes[] = {6, 64, 128, 512}; 
    int n_values[] = {10000, 100000, 1000000}; 
 
        int size = 6; 
        for(int j = 0; j < 3; j++) { 
            int n = n_values[j]; 
            ListArray myArray(size,10); 
            auto start = std::chrono::high_resolution_clock::now(); 
            for (int k = 0; k < n; k++) { 
                myArray.insert_right(k); 
            } 
            auto end = std::chrono::high_resolution_clock::now(); 
            std::chrono::duration<double> elapsed_time = end - start; 
            std::cout << "ListArray insert_right with size " << size << " and n " << n << " took " << elapsed_time.count() << " seconds." << std::endl; 
        } 
     
 
    return 0; 
}