#include <Siv3D.hpp>
#include "MrbPoint.hpp"
#include "mruby.h"
#include "mruby/irep.h"
#include "mruby/string.h"

static mrb_value mrb_println(mrb_state *mrb, mrb_value self)
{
    mrb_value str;
    mrb_get_args(mrb, "S", &str);
    Println(FromUTF8(mrb_string_value_ptr(mrb, str)));
    return mrb_nil_value();
}

static mrb_value mrb_wait_key(mrb_state *mrb, mrb_value self)
{
    WaitKey();
    return mrb_nil_value();
}

static mrb_value mrb_system_update(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(System::Update());
}

extern void mrb_siv3druby_circle_init(mrb_state *mrb);

void mrb_init(mrb_state *mrb)
{
    {
        struct RClass *krn = mrb->kernel_module;
        mrb_define_method(mrb, krn, "println", mrb_println, MRB_ARGS_REQ(1));
        mrb_define_method(mrb, krn, "wait_key", mrb_wait_key, MRB_ARGS_NONE());
    }

    {
        struct RClass *cc = mrb_define_module(mrb, "System");

        mrb_define_class_method(mrb, cc, "update", mrb_system_update, MRB_ARGS_NONE());
    }

    mrb_siv3druby_circle_init(mrb);
    siv3druby::MrbPoint::Init(mrb);
}
