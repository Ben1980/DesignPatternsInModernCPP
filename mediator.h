#include <vector>

struct IParticipant {
  virtual void setValue(int val) = 0;
};

struct Mediator {
  std::vector<IParticipant*> participants;
  
  void broadcast(IParticipant* participant, int value) {
    for(auto * p : participants) {
      if(p != participant) {
        p->setValue(value);
      }
    }
  }
};

struct Participant : IParticipant
{
    int value{0};
    Mediator& mediator;

    Participant(Mediator &mediator) : mediator(mediator)
    {
      mediator.participants.push_back(this);
    }

    void say(int value)
    {
       mediator.broadcast(this, value);
    }

    void setValue(int val) override {
      value = val;
    }
};
