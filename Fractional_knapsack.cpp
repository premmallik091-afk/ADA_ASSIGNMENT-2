
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    float weight[n], value[n], ratio[n];


    for (int i = 0; i < n; i++) {
        cout << "Enter weight and value: ";
        cin >> weight[i] >> value[i];
        ratio[i] = value[i] / weight[i];
    }

  
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                swap(ratio[j], ratio[j + 1]);
                swap(weight[j], weight[j + 1]);
                swap(value[j], value[j + 1]);
            }
        }
    }

    float capacity;
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    float totalValue = 0;

    for (int i = 0; i < n; i++) {
        if (capacity >= weight[i]) {
            totalValue += value[i];
            capacity -= weight[i];
        } else {
            totalValue += ratio[i] * capacity;
            break;
        }
    }

    cout << "Maximum value: " << totalValue;

    return 0;
}
