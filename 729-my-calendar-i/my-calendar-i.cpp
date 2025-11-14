class MyCalendar {
private:
    vector<pair<int, int>> books;

public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for (const auto& [start, end] : books) {
            if (max(start, startTime) < min(end, endTime)) {
                return false;
            }
        }
        books.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */