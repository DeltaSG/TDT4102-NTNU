#include <iostream>
#include <memory>
#include <vector>

#include "meeting.h"
#include "person.h"

//Overlaste << operator for en enum?
//Overlaste << uten friend? 
//lage en shared_ptr? opprette en shared_prt?

std::ostream& operator << (std::ostream& os , const Campus& a)
{
    switch(a)
    {
    case Campus::Trondheim: os << "Trondheim"; break;
    case Campus::Gjovik: os << "Gjovik"; break;
    case Campus::AAlesund: os << "AAlesund"; break;
    default: os<< "Not a valid Campus" ;break;
    } 
    return os;
}

int Meeting::getDay(){
    return day;
}
int Meeting::getStartTime(){
    return startTime;
}
int Meeting::getEndTime(){
    return endTime;
}
Campus Meeting::getLocation(){
    return location;
}
std::string Meeting::getSubject(){
    return subject;
}
std::string Meeting::getLeader(){
    return leader ->getName();
}
void Meeting::addParticipant(std::shared_ptr<Person> p){
    participants.push_back(p);
}
std::vector<std::shared_ptr<Person>> Meeting::findPotentialCoDriving(Meeting n)
{
    std::vector<std::shared_ptr<Person>> possibleCoDriving;
    if((n.location == location) and (n.day == day) and (abs(n.startTime - startTime) < 1) and (abs(n.endTime - endTime) > 1)){
        for(auto& person: n.participants){
            if(person ->hasAvailableSeats()){
                possibleCoDriving.push_back(person);
            }
        }
    }


    return possibleCoDriving;
}

std::vector<std::string> Meeting::getParticipantList(){
    std::vector<std::string> participantsName;
    for( auto& id: participants){
        participantsName.push_back(id ->getName());
    }
    return participantsName;
}

std::ostream& operator <<(std::ostream& os , Meeting& m)
{
    os << "Subject: " << m.getSubject() << ", Location: " << m.getLocation() << " , Start Time: " << m.getStartTime()
    << ", End Time: " << m.getEndTime() <<", Leader: " << m.getLeader() <<"." << std::endl;
    for(auto& elem:m.getParticipantList()){
        os << elem <<", ";
    }
    return os;
}