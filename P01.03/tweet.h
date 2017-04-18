#ifndef _TWEET_H
#define _TWEET_H

#include <string>
#include <ctime>
#include <iomanip>

class tweet
{
private:
	std::string text;
	int hour, min, sec;
public:
	tweet();
	tweet(std::string text);
	~tweet();
	friend std::ostream & operator << (std::ostream & stream, const tweet & _tweet);		// Ausgabeoperator �berladen
	friend bool operator == (const tweet & ltweet, const tweet & rtweet);					// Vergleichsoperator �berladen
	friend bool operator != (const tweet & ltweet, const tweet & rtweet);
};

tweet::tweet()
{
}

tweet::tweet(std::string text)
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	hour = ltm->tm_hour;
	min = ltm->tm_min;
	sec = ltm->tm_sec;
	this->text = text;
}

tweet::~tweet()
{
}

std::ostream & operator << (std::ostream  & stream, const tweet & _tweet)
{
	stream << std::setw(2) << std::setfill('0') << _tweet.hour << ":" <<_tweet.min << ":" << _tweet.sec << " -> " << _tweet.text;
	return stream;
}

inline bool operator==(const tweet & ltweet, const tweet & rtweet)
{
	if(rtweet.text == ltweet.text)
		return true;
	return false;
}

inline bool operator!=(const tweet & ltweet, const tweet & rtweet)
{
	if (rtweet.text != ltweet.text)
		return true;
	return false;
}


#endif