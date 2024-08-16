class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ans=0;
        queue<int>q;
        for(int i = 0 ; i < students.size() ; i++){
            q.push(students[i]);
        }
        int i = 0;
        int rotate = 0;

        while(!q.empty()){
            int top = q.front();
            q.pop();
            if(top == sandwiches[i]){
                i++;
                rotate = 0;
            }
            else{
                q.push(top);
                rotate++;
            }

            if(rotate == q.size()){
                break;
            }
        }   
        return q.size(); 
    }
};