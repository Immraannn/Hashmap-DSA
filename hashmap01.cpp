#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    // Create a HashMap (Key -> Value)
    unordered_map<int, string> mp;

    // ================= INSERT =================

    // Method 1
    mp[1] = "Apple";
    mp[2] = "Banana";

    // Method 2
    mp.insert({3, "Mango"});
    mp.insert(make_pair(4, "Orange"));

    // ================= DISPLAY =================
    cout << "HashMap elements:\n";
    for (auto it : mp) {
        cout << it.first << " -> " << it.second << endl;
    }

    // ================= ACCESS =================
    cout << "\nAccess key 2: " << mp[2] << endl;

    // Using at()
    cout << "Access key 3 using at(): " << mp.at(3) << endl;

    // ================= UPDATE =================
    mp[2] = "Grapes";

    cout << "\nAfter updating key 2:\n";
    cout << "2 -> " << mp[2] << endl;

    // ================= SEARCH =================
    if (mp.find(3) != mp.end())
        cout << "\nKey 3 Found\n";
    else
        cout << "\nKey 3 Not Found\n";

    // Another way using count()
    if (mp.count(5))
        cout << "Key 5 Found\n";
    else
        cout << "Key 5 Not Found\n";

    // ================= SIZE =================
    cout << "\nSize of HashMap = " << mp.size() << endl;

    // ================= DELETE =================
    mp.erase(4);

    cout << "\nAfter deleting key 4:\n";
    for (auto it : mp) {
        cout << it.first << " -> " << it.second << endl;
    }

    // ================= EMPTY =================
    if (mp.empty())
        cout << "\nHashMap is Empty\n";
    else
        cout << "\nHashMap is Not Empty\n";

    // ================= CLEAR =================
    mp.clear();

    cout << "\nAfter clear():\n";

    if (mp.empty())
        cout << "HashMap is Empty\n";
    else
        cout << "HashMap is Not Empty\n";

    return 0;
}
//output
// HashMap elements:
// 3 -> Mango
// 2 -> Banana
// 4 -> Orange
// 1 -> Apple

// Access key 2: Banana
// Access key 3 using at(): Mango

// After updating key 2:
// 2 -> Grapes

// Key 3 Found
// Key 5 Not Found

// Size of HashMap = 4

// After deleting key 4:
// 3 -> Mango
// 2 -> Grapes
// 1 -> Apple

// HashMap is Not Empty

// After clear():
// HashMap is Empty
