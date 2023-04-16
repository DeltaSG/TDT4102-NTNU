# pragma once


#include <iostream>
#include <memory>
#include <vector>
#include "person.h"


enum class Campus
{
    Trondheim,
    Gjovik,
    AAlesund
};

std::ostream& operator << (std::ostream& os , const Campus& a);


class Meeting
{
    private:
        int day;
        int startTime;
        int endTime;
        Campus location;
        std::string subject;
        const std::shared_ptr<Person> leader;
        std::vector<std::shared_ptr<Person>> participants;
    public:
        Meeting(int d, int st, int et, Campus local, std::string subj, std::shared_ptr<Person> lead):
        day{d} , startTime{st} , endTime{et} , location{local} , subject{subj} , leader{lead}{addParticipant(leader);};
        int getDay();
        int getStartTime();
        int getEndTime();
        Campus getLocation();
        std::string getSubject();
        std::string getLeader();
        void addParticipant(std::shared_ptr<Person> p);
        std::vector<std::string>(getParticipantList());
        std::vector<std::shared_ptr<Person>> findPotentialCoDriving(Meeting n);



};

std::ostream& operator <<(std::ostream& os , Meeting& m);
