#include <iostream>
#include <iomanip>
#include <list>
#include <forward_list>
#include<math.h>
#include <vector>
#include <algorithm>
#include<queue>
#include<stack>
#include<map>
using namespace std;

bool repeat()
{
    char ans;
    cout << "Do you want to run another function (P,p)->Yes: ";
    cin >> ans;
    if (ans == 'P' || ans == 'p')
    {
        return true;
    }
    return false;
};
struct ListNode
{
    int value;
    ListNode* next;
    ListNode* parent;
    ListNode(int x)
    {
        value = x;
        next = NULL;
    }
};

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
    {
        value = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    // 1 (Convert binary number into decimal number)
    // Time: O(n) -> because we iterate through the linked list twice 
    // Space: O(1)
    int getDecimalValue(ListNode* head) {
        int res = 0, count = 0;
        ListNode* temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        int exponent = count - 1;
        while (head != NULL)
        {
            res += head->value * pow(2, exponent);
            head = head->next;
            exponent--;
        }
        return res;
    }
    // 2 (The middle of the linked list)
    // Time: O(n) -> because we are iterating through the linked list once
    // Space: 0(1)
    ListNode* middleNode(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        while (second != NULL && second->next != NULL)
        {
            first = first->next;
            second = second->next->next;
        }
        return first;
    }
    // 3 (Reverse the list)
    // Time: O(n)
    // Space: O(1)
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        while (head != NULL)
        {
            ListNode* foward = head->next;
            head->next = prev;
            prev = head;
            head = foward;
        }
        return prev;
    }

    // 4 (Merge the two lists into one sorted list)
    // Time: O(n + m) -> n and m are the lengths of the two input lists.
    // Space: O(n + m)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
        {
            return list2;
        }
        if (list2 == nullptr)
        {
            return list1;
        }
        if (list1->value <= list2->value)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

    // 5 (Return true if it is a palindrome or false otherwise)
    // Time: O(n) -> because we iterate through the entire linked list once
    // Space: O(n) -> because we are storing all the values of the linked list in a vector
    bool isPalindrome(ListNode* head)
    {
        vector<int> vector;
        while (head != nullptr)
        {
            vector.push_back(head->value);
            head = head->next;
        }
        int left = 0, right = vector.size() - 1;
        while (left < right && vector[left] == vector[right])
        {
            left++;
            right--;
        }
        return left >= right;
    }
    //6
    int numIdenticalPairs(vector<int>& nums)
    {
        int k = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (nums[i] == nums[j] && i < j)
                {
                    k++;
                }
            }
        }
        return k;
    }
    //7
    // Time: O(nlogn) ->due to the sorting operation
    // Space: O(n) ->because we are using a map to store the indices of the sorted elements.
    vector<int> smallerNumbersThanCurrent(vector<int>& nums)
    {
        int length = nums.size();
        map <int, int> mp;
        vector <int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        for(int i = length - 1; i >= 0; i--){
            mp[sorted[i]] = i;
        }
        for(int i = 0; i < length; i++){

            nums[i] = mp[nums[i]];
        }

        return nums;
    }

    //8
    // Time: O(n) -> because we iterate through the string once.
    // Space: O(n) 
      char repeatedCharacter(string s)
    {
        map<char, int> m;

        for (int i = 0; i < s.size(); i++)
        {

            if (m.count(s[i]))
            {
                return s[i];
            }
            else
            {
                m[s[i]] = i;
            }
        }

        return ' ';
    }

    //9
    // Time: O(n + m) -> because we iterate through both strings once to populate the map with jewels
    // Space: O(n) -> because we store the unique jewels in a map.
    int numJewelsInStones(string jewels, string stones) {
        map<char, bool> jw;

        for (auto x : jewels) {
            jw[x] = true;
        }
        int count = 0;
        for (auto x : stones) {
            if (jw[x]) {
                count++;
            }
        }

        return count;
    }

    //10
    // Time: O(n) -> because the function iterates through the strings once to build the maps sMap and tMap
    // Space: O(n) ->because the function uses two maps, sMap and tMap
    int findPermutationDifference(string s, string t) {
        int sum = 0;
        map<char, int> sMap;
        map<char, int> tMap;

        for (int i = 0;i < s.size();i++)
        {
            sMap[s[i]] = i;
            tMap[t[i]] = i;
        }

        for (int i = 0;i < s.size();i++)
        {
            sum += (abs(sMap[s[i]] - tMap[s[i]]));
        }

        return sum;
    }

    //Krijimi i pemes binare
    TreeNode* buildBinaryTree() 
    {
        int val;
        cout << "Enter node value (-1 for NULL): ";
        cin >> val;

        if (val == -1) {
            return nullptr; // Return null pointer for null node
        }

        TreeNode* newNode = new TreeNode(val);

        cout << "Enter left child of " << val << ":\n";
        newNode->left = buildBinaryTree();

        cout << "Enter right child of " << val << ":\n";
        newNode->right = buildBinaryTree();

        return newNode;
    }

    // 11 (Return the sum of values of all nodes with a value in the inclusive range [low, high].)
    // Time: O(n) -> because the function recursively visits each node in the tree exactly once
    // Space: O(n) -> as the function makes recursive calls that can potentially stack up to a depth of n
    int rangeSumBST(TreeNode* root, int low, int high) 
    {

        int value = 0;
        if (root == NULL)
        {
            return value;
        }

        if (root->value >= low && root->value <= high)
        {
            value = root->value;
        }

        return value +
            rangeSumBST(root->left, low, high) +
            rangeSumBST(root->right, low, high);
    }

    // 12 (Search for a number in BST)
    // Time: O(log(n)) or O(n) -> in the average case either goes left or right,  in the worst case the algorithm may have to visit all nodes
    // Space: O(h) (h is the height of the binary search tree) -> ecause the algorithm uses recursive calls
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->value == val)
        {
            return root;
        }
        else if (root->value > val)
        {
            return searchBST(root->left, val);
        }
        else
        {
            return searchBST(root->right, val);
        }
    }

    // 13 
    // Time: O(n) -> because for each element in the array, we are creating a new TreeNode
    // Space: O(n) -> because we are creating new vectors for the left and right
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return nullptr;
        }
        int mid = nums.size() / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        vector<int>left(nums.begin(), nums.begin() + mid);
        root->left = sortedArrayToBST(left);
        vector<int>right(nums.begin() + mid + 1, nums.end());
        root->right = sortedArrayToBST(right);
        return root;
    }

    //14
    // Time: O(n^2) -> because we are iterating through all nodes in the tree to populate the vector v with their values,
    // and then we are iterating through the vector v twice to check for pairs of values that sum up to k.
    // Space: O(n) -> because we are using a vector v to store the values of all nodes in the tree.
    vector<int>v;
    void members(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        v.push_back(root->value);
        members(root->left);
        members(root->right);
    }

    bool findTarget(TreeNode* root, int k) 
    {
        members(root);
        for (int i = 0; i < v.size();i++)
        {
            for (int j = 0;j < v.size();j++)
            {
                if (v.at(i) + v.at(j) == k && i != j)
                {
                    return true;
                }
            }
        }
        return false;
    }

    //15
    // Time: O(nlogn) -> because we are traversing both trees to collect all elements, 
    // which takes O(n) time, and then sorting the collected elements, which takes O(nlogn) time.
    // Space: O(n) -> because we are using a vector to store all the elements from both trees
    void members1(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        v.push_back(root->value);
        members1(root->left);
        members1(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        members1(root1);
        members1(root2);
        sort(v.begin(), v.end());
        return v;
    }

    //16
    // Time: O(n^2) -> because there are two nested loops
    // Space: O(1) 
    int firstUniqChar(string s) 
    {
        for (int i = 0;i < s.size();i++)
        {
            bool isUnique = true;
            for (int j = 0;j < s.size();j++)
            {
                if (i != j && s[i] == s[j])
                {
                    isUnique = false;
                    break;
                }

            }
            if (isUnique)
            {
                return i;
            }
        }
        return -1;
    }

    //19
    // Time: O(n) -> because the function iterates through the entire string once
    // Space: O(1)
    int maxDepth(string s) 
    {
        int ans = 0;
        int t = 0;
        for (int i = 0; i < s.length();i++)
        {
            if (s[i] == '(')
            {
                t++;
            }
            else if (s[i] == ')')
            {
                ans = max(ans, t);
                t--;
            }
        }
        return ans;
    }

    //20
    // Time:  O(n) -> because we iterate through each character in the string once.
    // Space:  O(n) -> because we use a stack to keep track of opening brackets
    bool isValid(string s) {
        stack<char>e;
        for (int i = 0; i < s.length();i++)
        {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{')
            {
                e.push(c);
            }
            else
            {
                if (e.empty())
                {
                    return false;
                }
                char top = e.top();
                if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{'))
                {
                    e.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return e.empty();
    }
};
//17 
// Space: O(n) -> because we are using a queue to store the elements of the stack
class MyStack {
public:
    queue<int>q;
    MyStack() {

    }

    // Time: O(n) -> because for each push operation, we need to iterate through all the elements in the queue
    void push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 0; i < size - 1; ++i)
        {
            q.push(q.front());
            q.pop();
        }
    }
    // Time:  O(1)
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    // Time:  O(1)
    int top() {
        return q.front();
    }
    // Time:  O(1)
    bool empty() {
        return q.empty();
    }
};

//18
// Space: O(n) ->because we are using an additional stack to store the elements temporarily 
class MyQueue {
public:
    stack<int> s;
    MyQueue() {

    }
    // Time: O(n) -> because each push operation recursively pops all elements from the stack until it reaches the bottom
    void push(int x)
    {
        if (s.empty()) {
            s.push(x);
        }
        else {
            int temp = s.top();
            s.pop();
            push(x);
            s.push(temp);
        }
    }
    // Time:  O(1)
    int pop() {
        int top = s.top();
        s.pop();
        return top;
    }
    // Time:  O(1)
    int peek() {
        return s.top();
    }
    // Time:  O(1)
    bool empty() {
        return s.empty();
    }
};
int main()
{
    int numOfFunction = 0;
    Solution s;
    cout << endl << "A simple program including 20 functions." << endl;
    beginning:
    cout << "\nList of functions and their corresponding number:" << endl;
    cout << "1. Convert binary number in a linked list to integer. " << endl;
    cout << "2. Middle of the linked list." << endl;
    cout << "3. Reverse linked list." << endl;
    cout << "4. Merge Two Sorted Lists." << endl;
    cout << "5. Palindrome Linked List. " << endl;
    cout << "6. Number of Good Pairs. " << endl;
    cout << "7. How many Numbers are Smaller than the Current Number. " << endl;
    cout << "8. First Letter to Appear Twice " << endl;
    cout << "9. Jewels and Stones. " << endl;
    cout << "10. Permutation Difference Between two Strings." << endl;
    cout << "11. Range Sum of BST. " << endl;
    cout << "12. Search in a Binary Search Tree. " << endl;
    cout << "13. Convert Sorted Array to Binary Search Tree." << endl;
    cout << "14. Two Sum IV - Input is a BST." << endl;
    cout << "15. All Elements in Two Binary Search Trees." << endl;
    cout << "16. First Unique Character in a String." << endl;
    cout << "17. Implement Stack using Queues." << endl;
    cout << "18. Implement Queue using Stacks." << endl;
    cout << "19. Maximum Nesting Depth of the Parentheses." << endl;
    cout << "20. Valid Parentheses. " << endl;
    cin >> numOfFunction;

    switch (numOfFunction)
    {
    case (1):
    {
        ListNode* mainNode = nullptr;
        int members, member;
        cout << "\nGiven head which is a reference node to a singly-linked list. ";
        cout << " The value of each node in the linked list is either 0 or 1. " << endl;
        cout << "Return the decimal value of the number in the linked list. " << endl;

        cout << "Enter the number of members in the list: ";
        cin >> members;
        cout << "Enter the binary numbers for each member (0 or 1):" << endl;
        for (int i = 0; i < members; i++)
        {
        again:
            cout << "Member " << i + 1 << ":";
            cin >> member;

            if (member != 0 && member != 1)
            {
                cout << "You have entered the wrong member! " << endl;
                goto again;
            }

            if (mainNode == nullptr)
            {
                mainNode = new ListNode(member);
                mainNode->parent = nullptr;
            }
            else
            {
                ListNode* newNode = new ListNode(member);
                newNode->parent = mainNode;
                mainNode->next = newNode;

                mainNode = mainNode->next;
            }
        }

        while (mainNode->parent != nullptr)
        {
            mainNode = mainNode->parent;
        }
        cout << "The decimal value of the number in the linked list is : " << s.getDecimalValue(mainNode) << endl;
        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;
    }
    case(2):
    {
        ListNode* head = nullptr;
        ListNode* current = nullptr;
        int members, member;
        cout << endl << " Given the head of a singly linked list, return the middle node of the linked list." << endl;
        cout << "Enter the number of members in the list: ";
        cin >> members;
        for (int i = 0; i < members; i++)
        {
            cout << "Member " << i + 1 << " : ";
            cin >> member;
            ListNode* newNode = new ListNode(member);
            if (head == nullptr)
            {
                head = newNode;
                current = head;
            }
            else
            {
                current->next = newNode;
                current = current->next;
            }
        }
        ListNode* middle = s.middleNode(head);
        cout << "Middle value: " << middle->value << endl;

        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;

    }
    case(3):
    {
        ListNode* head = nullptr;
        ListNode* current = nullptr;
        int members, member;
        cout << " Given the head of a singly linked list, reverse the list, and return the reversed list." << endl;
        cout << "Enter the number of members in the list: ";
        cin >> members;
        for (int i = 0; i < members; i++)
        {
            cout << "Member: " << i + 1 << " :";
            cin >> member;
            ListNode* newNode = new ListNode(member);
            if (head == nullptr)
            {
                head = newNode;
                current = head;
            }
            else
            {
                current->next = newNode;
                current = current->next;
            }
        }
        ListNode* reversed = s.reverseList(head);

        cout << "Reversed list: " << endl;
        while (reversed != NULL)
        {
            cout << reversed->value << " ";
            reversed = reversed->next;
        }
        cout << endl;

        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;
    }
    case(4):
    {
        cout << "You are given the heads of two sorted linked lists list1 and list2." << endl;
        cout << "Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists." << endl;
        cout << "Return the head of the merged linked list.";

        ListNode* list1 = nullptr;
        ListNode* current1 = nullptr;
        int members;
        cout << endl << "Enter the number of members in the list: ";
        cin >> members;
        for (int i = 1; i <= members; i++)
        {
            ListNode* newNode = new ListNode(i * 3);
            if (list1 == nullptr)
            {
                list1 = newNode;
                current1 = list1;
            }
            else
            {
                current1->next = newNode;
                current1 = current1->next;
            }
        }

        ListNode* list2 = nullptr;
        ListNode* current2 = nullptr;
        cout << endl << "Enter the number of members in list2: ";
        cin >> members;
        for (int i = 1; i <= members; i++)
        {
            ListNode* newNode = new ListNode(i * 2);
            if (list2 == nullptr)
            {
                list2 = newNode;
                current2 = list2;
            }
            else
            {
                current2->next = newNode;
                current2 = current2->next;
            }
        }
        ListNode* mergedList = s.mergeTwoLists(list1, list2);
        cout << "Merged list: ";
        ListNode* tempMerged = mergedList;
        while (tempMerged != nullptr)
        {
            cout << tempMerged->value << " ";
            tempMerged = tempMerged->next;
        }
        cout << endl;
        while (list1 != nullptr)
        {
            ListNode* temp = list1;
            list1 = list1->next;
            delete temp;
        }

        while (list2 != nullptr)
        {
            ListNode* temp = list2;
            list2 = list2->next;
            delete temp;
        }
        while (mergedList != nullptr)
        {
            ListNode* temp = mergedList;
            mergedList = mergedList->next;
            delete temp;
        }

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;
    }
    case(5):
    {
        cout << "Given the head of a singly linked list, return true if it is a  palindrome or false otherwise." << endl;
        int members, member;
        ListNode* head = nullptr;
        cout << endl << "Enter the number of members in the list: ";
        cin >> members;

        for (int i = 0; i < members; i++)
        {
            cout << "Member " << i + 1 << " :";
            cin >> member;
            ListNode* newNode = new ListNode(member);
            newNode->next = head;
            head = newNode;
        }
        bool isPal = s.isPalindrome(head);
        if (isPal)
        {
            cout << "The linked list is a palindrome." << endl;
        }
        else
        {
            cout << "The linked list isn't a palindrome." << endl;
        }

        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;

    }
    case (6):
    {
        int elements;
        cout << "Given an array of integers nums, return the number of good pairs." << endl;
        cout << "A pair (i, j) is called good if nums[i] == nums[j] and i < j." << endl;
        cout << "Enter the number of members in the vector: ";
        cin >> elements;
        vector <int> vector;
        for (int i = 0; i < elements; i++)
        {
            int members;
            cout << "Element [" << i + 1 << "]: ";
            cin >> members;
            vector.push_back(members);
        }
        cout << "\nThe given vector:\n";
        for (int i = 0; i < elements; i++)
        {
            cout << vector[i] << setw(6);
        }
        int numberofGoodPairs = s.numIdenticalPairs(vector);
        if (numberofGoodPairs != 1)
        {
            cout << "\nThere are " << numberofGoodPairs << " good pairs in the given vector " << endl;
        }
        else
        {
            cout << "\nThere is " << numberofGoodPairs << " good pair in the given vector " << endl;
        }

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;

    }
    case(7):
    {
        cout << "Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it.";
        cout << "That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i]." << endl;
        cout << "Return the answer in an array." << endl;
        int elements;
        cout << "Enter the number of members in the vector: ";
        cin >> elements;
        vector <int> nums;
        for (int i = 0; i < elements; i++)
        {
            int number;
            cout << "Element [" << i + 1 << "]: ";
            cin >> number;
            nums.push_back(number);
        }

        vector<int>result = s.smallerNumbersThanCurrent(nums);

        cout << "\nThe given vector:\n";
        cout << "[";
        for (int i = 0; i < elements; i++)
        {
            cout << nums[i];
            if (i < elements - 1)
                cout << ",";
        }
        cout << "]" << endl;

        cout << "\nResult: " << endl;
        cout << "[";
        for (int i = 0; i < elements; i++)
        {
            cout << result.at(i);
            if (i < elements - 1)
            {
                cout << ",";
            }
        }
        cout << "]" << endl;

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;

    }
    case(8):
    {
         string input;
    cout << "Enter a string: ";
    cin >> input;  // Input a string using cin

    char result = repeatedCharacter(input); // Call the function to find the repeated character
    if (result != ' ') 
    {
        cout << "First repeated character: " << result << endl;  // Print the result
    } 
    else 
    {
        cout << "No repeated character found." << endl;
    }

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;
    }
    case(9):
    {
        cout << "You're given strings jewels representing the types of stones that are jewels," <<
            " and stones representing the stones you have." << endl;
        cout << "Each character in stones is a type of stone you have."
            << " You want to know how many of the stones you have are also jewels." << endl;
        string jewels, stones;

        cout << "Enter the types of jewels: ";
        cin >> jewels;

        cout << "Enter the stones you have: ";
        cin >> stones;

        int jewelCount = s.numJewelsInStones(jewels, stones);
        cout << "Number of jewels in stones: " << jewelCount << endl;

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;
    }
    case(10):
    {
        cout << "You are given two strings s and t such that every character occurs at most once in r and t is a permutation of r." << endl;
        cout << "The permutation difference between r and t is defined as the sum of the absolute difference between the index of ";
        cout << "the occurrence of each character in r and the index of the occurrence of the same character in t." << endl;
        cout << "\n Return the permutation difference between r and t." << endl;

        string r, t;

        cout << "Enter the first permutation string (r): ";
        cin >> r;

        cout << "Enter the second permutation string (t): ";
        cin >> t;

        int difference = s.findPermutationDifference(r, t);
        cout << "The permutation difference between " << r << " and " << t << " is: " << difference << endl;

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;
    }
    case(11):
    {
        cout << "Given the root node of a binary search tree and two integers low and high,"
            << "return the sum of values of all nodes with a value in the inclusive range [low, high]." << endl;
        TreeNode* root = s.buildBinaryTree();
        int low, high, result;
        cout << "Enter a low number: ";
        cin>>low;
        cout << "Enter high number: ";
        cin>>high;
        result = s.rangeSumBST(root, low, high);
        cout << "Sum of values within the range [" << low << ", " << high << "]: " << result << endl;

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;
    }
    case(12):
    {
        cout << "\nYou are given the root of a binary search tree (BST) and an integer val." << endl;
        cout << "\nFind the node in the BST that the node's value equals val and return the subtree rooted with that node. ";
        cout << "If such a node does not exist, return null." << endl;
        TreeNode* root = s.buildBinaryTree();
        int val;
        cout << "Enter a value to find: ";
        cin >> val;
        TreeNode* result = s.searchBST(root, val);
        if (result == NULL)
        {
            cout << "Node with value " << val << " not found in the BST." << endl;
        }
        cout << "Node with value " << val << " is found in the BST." << endl;

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;
    }
    case(13):
    {
        cout << "\nGiven an integer array nums where the elements are sorted in ascending order, "
            << "convert it to a height - balanced binary search tree." << endl;
        vector<int>num;
        int members;
        cout << "Enter the number of elements in the array: ";
        cin >> members;
        for (int i = 0; i < members; i++)
        {
            int number;
            cout << "Element [" << i + 1 << "]" << ":";
            cin >> number;
            num.push_back(number);
        }
        TreeNode* root = s.sortedArrayToBST(num);

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;
    }
    case(14):
    {
        cout << "Given the root of a binary search tree and an integer k,"
            << " return true if there exist two elements in the BST such that"
            << "their sum is equal to k, or false otherwise." << endl;
        TreeNode* root = s.buildBinaryTree();
        int k;
        cout << "Enter a integer value:";
        cin >> k;
        bool result = s.findTarget(root, k);
        if (result)
        {
            cout << "Found two numbers that sum up to " << k << ".\n";
        }
        else
        {
            cout << "No two numbers found that sum up to " << k << ".\n";
        }

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;
    }
    case(15):
    {
        cout << "Given two binary search trees root1 and root2, "
            << " return a list containing all the integers from both trees sorted in ascending order." << endl;
        cout << "\nEnter elements for first binary tree:\n";
        TreeNode* root1 = s.buildBinaryTree();
        cout << endl;
        cout << "Enter elements for second binary tree:\n";
        TreeNode* root2 = s.buildBinaryTree();

        vector<int>v = s.getAllElements(root1, root2);
        cout << "\nAll elements from both trees in sorted order:\n";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v.at(i) << " ";
        }
        cout << endl;

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;
    }
    case(16):
    {
        cout << "Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1." << endl;
        string s1;
        cout << "Enter a string: ";
        cin >> s1;
        bool result = s.firstUniqChar(s1);
        if (result != -1) {
            cout << "Index of the first non-repeating character: " << result << endl;
        }
        else {
            cout << "No non-repeating character found." << endl;
        }

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;

    }
    case(17):
    {
        cout << "Implement a last-in-first-out (LIFO) stack using only two queues." <<endl;
        cout << "The implemented stack should support all the functions of a normal stack (push, top, pop, and empty)." << endl;
        MyStack stack;
        stack.push(4);
        stack.push(6);
        stack.pop();
        stack.push(9);
        stack.push(1);
        stack.pop();
        stack.push(99);
        stack.push(13);
        stack.pop();
        cout << "Top of the stack: " << stack.top() << endl;
        cout << "Elements of the stack: ";
        while (!stack.empty())
        {
            cout << stack.top() << " ";
            stack.pop();
        }

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;
    }
    case(18):
    {
        cout << "Implement a first in first out (FIFO) queue using only two stacks. " << endl;
        cout << "The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty)." << endl;
        MyQueue queue;
        queue.push(6);
        queue.push(11);
        queue.pop();
        queue.push(2);
        queue.push(9);
        queue.pop();
        queue.push(19);
        queue.push(5);
        queue.pop();
        cout << "Top of the queu: " << queue.peek() << endl;
        cout << "Elements of the queue: ";
        while (!queue.empty())
        {
            cout << queue.peek() << " ";
            queue.pop();
        }

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;
    }
    case(19):
    {
        cout << "Given a valid parentheses string s, return the nesting depth of s. "
            << " The nesting depth is the maximum number of nested parentheses." << endl;
        string e;
        cout << "Enter a valid parentheses string: ";
        cin >> e;
        int result = s.maxDepth(e);
        cout << "Maximum nesting depth: " << result << endl;

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;
    }
    case(20):
    {
        cout << "Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', "
            << " determine if the input string is valid." << endl;
        cout << "An input string is valid if:" << endl;
        cout << endl << "1.Open brackets must be closed by the same type of brackets." << endl;
        cout << endl << "2.Open brackets must be closed in the correct order." << endl;
        cout << endl << "3.Every close bracket has a corresponding open bracket of the same type." << endl;

        string input;
        cout << "Enter a string containing only parentheses, square brackets, and curly brackets: ";
        cin >> input;
        bool result = s.isValid(input);
        if (result)
        {
            cout << "The input string contains valid brackets." << endl;
        }
        else
        {
            cout << "The input string does not contain valid brackets." << endl;
        }

        bool rep = repeat();
        if (rep)
        {
            goto beginning;
        }
        break;
    }
    default:
    {
        cout << "The function with the given number does not exist in the list!" << endl;
        cout << "Please look the list function and put another number." << endl;
        goto beginning;
    }
    }

}

