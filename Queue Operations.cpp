//User function Template for C++
// Helper class Solution to implement 
// insert() and findFrequency()
class Solution {
public:

    // Function to insert an element into the queue
    void insert(queue<int> &queueObj, int element) {
        queueObj.push(element);
    }

    // Function to find the frequency of an element
    // Return the frequency of 'target'
    int findFrequency(queue<int> &queueObj, int target) {
        queue<int> tempQueue;
        int frequency = 0;

        while (!queueObj.empty()) {
            tempQueue.push(queueObj.front());
            frequency += (queueObj.front() == target);
            queueObj.pop();
        }

        while (!tempQueue.empty()) {
            queueObj.push(tempQueue.front());
            tempQueue.pop();
        }

        return frequency;
    }

};
