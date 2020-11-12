/*
Buy the ticket
Send Feedback
You want to buy a ticket for a well-known concert which is happening in your city. But the number of tickets available is limited. Hence the sponsors of the concert decided to sell tickets to customers based on some priority.
A queue is maintained for buying the tickets and every person has attached with a priority (an integer, 1 being the lowest priority). The tickets are sold in the following manner -
1. The first person (pi) in the queue asked to comes out.
2. If there is another person present in the queue who has higher priority than pi, then ask pi to move at end of the queue without giving him the ticket.
3. Otherwise, give him the ticket (and don't make him stand in queue again).
Giving a ticket to a person takes exactly 1 minutes and it takes no time for removing and adding a person to the queue. And you can assume that no new person joins the queue.
Given a list of priorities of N persons standing in the queue and the index of your priority (indexing starts from 0). Find and return the time it will take until you get the ticket.
Input Format :
Line 1 : Integer N (Total number of people standing in queue)
Line 2 : Priorities of every person (n space separated integers)
Line 3 : Integer k (index of your priority)
Output Format :
Time required
Sample Input 1 :
3
3 9 4
2
Sample Output 1 :
2
Sample Output 1 Explanation :
Person with priority 3 comes out. But there is a person with higher priority than him. So he goes and then stands in the queue at the end. Queue's status : {9, 4, 3}. Time : 0 secs.
Next, the person with priority 9 comes out. And there is no person with higher priority than him. So he'll get the ticket. Queue's status : {4, 3}. Time : 1 secs.
Next, the person with priority 4 comes out (which is you). And there is no person with higher priority than you. So you'll get the ticket. Time : 2 secs.
Sample Input 2 :
5
2 3 2 2 4
3
Sample Output 2 :
4

*/

#include<queue>
using namespace std;
int buyTicket (int *arr, int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int t=0;
    queue<int> q;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        q.push(i);
        pq.push(arr[i]);
    }
    // for(int i=0;i<n;i++){
    //     cout<<q.front()<<endl;
    //     q.pop();
    // }
    
    while(q.front()!=k || pq.top()!=arr[k])
    if(arr[q.front()]==pq.top()){
        t++;
        q.front();
        pq.pop();
    }
    else{
        q.push(q.front());
        q.pop();
    }
    return t+1;
    
    
}

/*
#include <iostream>
#include <vector>
using namespace std;
#include "solution.h"


int main(){
    int n, k, s;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> k;
    cout << buyTicket(arr, n, k) << endl;
}

*/

/*
other solution-
#include <queue>

int buyTicket (int *input, int n, int k){
    queue<int> q;
    
    // Max priority queue
    priority_queue<int> pq;
    
    for(int i = 0; i < n; i++) {
        q.push(input[i]);
        pq.push(input[i]);
    }
    int count = 0;
    while(!pq.empty()) {
        if(q.front() == pq.top()) {
            if(k == 0) {
                return count + 1;
            }
            else {
                count++;
                q.pop();
                pq.pop();
                k--;
            }
        }
        else {
            q.push(q.front());
            q.pop();
            if(k == 0) {
                k = q.size() - 1;
            }
            else {
                k--;
            }
        }
    }
    return count;
    
}
*/