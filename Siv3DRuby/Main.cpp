#include <Siv3D.hpp>
#include "mruby.h"
#include "mruby/compile.h"

extern void mrb_init(mrb_state *mrb);

void Main()
{
	mrb_state* mrb = mrb_open();
	mrb_init(mrb);

	FILE* fp;
	fopen_s(&fp, "main.rb", "r");
	{
		mrb_value ret = mrb_load_file(mrb, fp);
	}
	fclose(fp);

	mrb_close(mrb);
}
