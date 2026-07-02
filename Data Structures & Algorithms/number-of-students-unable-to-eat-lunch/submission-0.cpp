class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> q;
        for (int student: students) q.push(student);

        int result = n;
        for (int sandwich: sandwiches) {
            //begin to rotate if needed
            int count = 0;
            while (count < n && q.front() != sandwich) {
                q.push(q.front());
                q.pop();
                count++;
            }
            if (q.front() == sandwich) {
                result--;
                q.pop();
            } else break;
        }
        return result;
    }
};