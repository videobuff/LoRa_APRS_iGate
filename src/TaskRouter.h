#ifndef TASK_ROUTER_H_
#define TASK_ROUTER_H_

#include <APRSMessage.h>
#include <TaskManager.h>

class RouterTask : public Task {
public:
  RouterTask(TaskQueue<std::shared_ptr<APRSMessage>> *const fromModem, TaskQueue<std::shared_ptr<APRSMessage>> *const toAprsIs);
  virtual ~RouterTask();

  virtual bool setup(std::shared_ptr<System> system) override;
  virtual bool loop(std::shared_ptr<System> system) override;

private:
  TaskQueue<std::shared_ptr<APRSMessage>> *const _fromModem;
  TaskQueue<std::shared_ptr<APRSMessage>> *const _toAprsIs;

  std::shared_ptr<APRSMessage> _beaconMsg;
  Timer                        _beacon_timer;
};

#endif