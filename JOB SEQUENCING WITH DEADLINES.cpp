#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    int id[n], deadline[n], profit[n];

    
    for (int i = 0; i < n; i++) {
        cout << "Enter id, deadline, profit: ";
        cin >> id[i] >> deadline[i] >> profit[i];
    }

  
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {
                swap(profit[j], profit[j + 1]);
                swap(deadline[j], deadline[j + 1]);
                swap(id[j], id[j + 1]);
            }
        }
    }

    
    int maxD = 0;
    for (int i = 0; i < n; i++) {
        if (deadline[i] > maxD)
            maxD = deadline[i];
    }

    int slot[maxD + 1];
    for (int i = 0; i <= maxD; i++)
        slot[i] = -1;

    int totalProfit = 0;

    
    for (int i = 0; i < n; i++) {
        for (int j = deadline[i]; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = id[i];
                totalProfit += profit[i];
                break;
            }
        }
    }


    cout << "\nJobs done: ";
    for (int i = 1; i <= maxD; i++) {
        if (slot[i] != -1)
            cout << slot[i] << " ";
    }

    cout << "\nTotal Profit: " << totalProfit;

    return 0;
}
