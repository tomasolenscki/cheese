#ifndef TASK_SWITCHER_H_INCLUDED
#define TASK_SWITCHER_H_INCLUDED

#define MAX_TAREFAS 4

typedef struct {
void (*task)();
long     interval;
long     current_time;
int      status;
} TaskControl;

class TaskSwitcher {
  public:
  TaskSwitcher();
  void begin(long timerInterruptInuSecs);
  void createTask(void (*t)(), long interval);
  void runCurrentTask();
  void updateTickCounter();

  private:
  TaskControl taskList[MAX_TAREFAS];
  int taskCount;
};

extern TaskSwitcher TaskController;

#endif // TASK_SWITCHER_H_INCLUDED