struct Command
{
  enum Action { deposit, withdraw } action;
  int amount{0};
  bool success{false};
};

struct Account
{
  int balance{0};

  void process(Command& cmd)
  {
    switch (cmd.action) {
      case Command::deposit:
        balance += cmd.amount;
        cmd.success = true;
        break;
      case Command::withdraw:
        cmd.success = (balance >= cmd.amount);
        if (cmd.success) balance -= cmd.amount;
        break;
    }
  }
};
