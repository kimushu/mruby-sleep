#include "mruby.h"
#include <unistd.h>

static mrb_value
mrb_ker_usleep(mrb_state *mrb, mrb_value self)
{
  mrb_int usecs;
  mrb_get_args(mrb, "i", &usecs);
  usleep(usecs);
  return mrb_nil_value();
}

static mrb_value
mrb_ker_msleep(mrb_state *mrb, mrb_value self)
{
  mrb_int msecs;
  mrb_get_args(mrb, "i", &msecs);
  for (; msecs > 0; --msecs) {
    usleep(1000);
  }
  return mrb_nil_value();
}

static mrb_value
mrb_ker_sleep(mrb_state *mrb, mrb_value self)
{
  mrb_int secs;
  mrb_get_args(mrb, "i", &secs);
  sleep(secs);
  return mrb_nil_value();
}

void
mrb_mruby_sleep_gem_init(mrb_state *mrb)
{
  mrb_define_method(mrb, mrb->kernel_module, "usleep", mrb_ker_usleep, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, mrb->kernel_module, "msleep", mrb_ker_msleep, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, mrb->kernel_module, "sleep" , mrb_ker_sleep , MRB_ARGS_REQ(1));
}

void
mrb_mruby_sleep_gem_final(mrb_state *mrb)
{
}

