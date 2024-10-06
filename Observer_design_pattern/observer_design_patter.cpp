#include<bits/stdc++.h>

using namespace std;
class Subscriber;

class Youtube {
private:
    string Name;
    vector<Subscriber*> subscribers; // List of subscribers
    string latestVideo;

public:
    Youtube(const string& name) : Name(name) {}

    void subscribe(Subscriber* subscriber);
    void unsubscribe(Subscriber* subscriber);
    void notifySubscribers();
    void uploadVideo(const string& videoTitle);
};

class Subscriber {
private:
    string name;

public:
    Subscriber(const string& subscriberName) : name(subscriberName) {}

    void update(const string& videoTitle) {
        cout << name << " received a notification for new video: " << videoTitle << endl;
    }

    // to access the private members of the Youtube class
    friend class Youtube; 
};

// subscribe to a channel
void Youtube::subscribe(Subscriber* subscriber) {
    subscribers.push_back(subscriber);
}

// unsubscribe from a channel
void Youtube::unsubscribe(Subscriber* subscriber) {
    subscribers.erase(remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end());
}

// Notify all subscribers about a new video
void Youtube::notifySubscribers() {
    for (Subscriber* subscriber : subscribers) {
        subscriber->update(latestVideo);
    }
}

// Upload a new video and notify subscribers
void Youtube::uploadVideo(const string& videoTitle) {
    latestVideo = videoTitle;
    cout << Name << " uploaded a new video: " << videoTitle << endl;
    notifySubscribers();
}

// Example usage
int main() {
    Youtube channel("Mr. Beast");
    Subscriber Prasoon("prasoon");
    Subscriber Priya("priya");

    channel.subscribe(&Prasoon);
    channel.subscribe(&Priya);

    channel.uploadVideo("Observer Design Pattern in C++");

    channel.unsubscribe(&Prasoon);
    channel.uploadVideo("More C++ Tips");

    return 0;
}
