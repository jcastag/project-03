/*
 * mailbox.cc
 * Copyright(c) 2022 Dongsoo S. Kim
 */
/**TODO
 * [] turn packet into letter
 * [] add letter to queues
 * [] pop letter from queues
 */
#include <iostream>
#include <string.h>
#include <map>
#include <queue>
#include <mutex>
#include <chrono>
#include "graph.h"
#include "mbox.h"

class MailBox
{
  struct msg
  {
    int length;
    int to;
    int from;
    int hopCount;
    // also need to add chrono timestamp for time made
    char *content;
  };

  typedef std::queue<msg> mailbox_t;
  std::map<uint16_t, mailbox_t> _mailboxes;
  std::mutex mtx;

public:
  MailBox(){};
  ~MailBox();
  bool empty(uint16_t mid);
  bool mbox_avail(uint16_t mid);

  int send(uint16_t mid, const void *packet, int len);
  int recv(uint16_t mid, void *packet, int max);
};

int MailBox::send(uint16_t mID, const void *packet, int length)
{

  mtx.lock();
  // add to mailbox's queue
  // mailbox._mailboxes[mID].push(&packet);
  mtx.unlock();

  return 0;
}

int MailBox::recv(uint16_t mid, void *packet, int max)
{
  mtx.lock();
  // dequeueing
  mtx.unlock();

  return 0;
}

static MailBox mailbox;

MailBox::~MailBox()
{
  struct msg xtem;
  mtx.lock();
  for (auto x : _mailboxes)
  {
    while (!x.second.empty())
    {
      xtem = x.second.front();
      x.second.pop();
      delete[] xtem.content;
    }
  }
  mtx.unlock();
}

bool MailBox::empty(uint16_t mid)
{
  if (this->_mailboxes[mid].empty())
    return true;
  else
    return false;
}

bool mbox_empty(uint16_t mid)
{
  return mailbox.empty(mid);
}

bool mbox_avail(uint16_t mid)
{
  return true;
}

int mbox_send(uint16_t mid, const void *packet, int len)
{
  return mailbox.send(mid, packet, len);
}

int mbox_recv(uint16_t mid, void *packet, int max)
{
  return mailbox.recv(mid, packet, max);
}
