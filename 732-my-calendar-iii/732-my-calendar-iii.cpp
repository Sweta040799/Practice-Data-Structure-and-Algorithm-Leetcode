class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int mxcnt = 0;
    map<int, int> mp;
    
    int book(int start, int end) {
        int cnt = 0;
        mp[start]++;
        mp[end]--;
        
        for(auto it: mp){
            cnt += it.second;
            mxcnt = max(mxcnt, cnt);
        }
        
        return mxcnt;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */