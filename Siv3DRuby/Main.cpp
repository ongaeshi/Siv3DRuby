
#include <Siv3D.hpp>
#include "mruby.h"
#include "mruby/irep.h"
#include "mruby/compile.h"
#include "mruby/string.h"

void Main()
{
	mrb_state* mrb = mrb_open();
	//mrb_init(mrb);

	FILE* fp;
	fopen_s(&fp, "main.rb", "r");
	{
		mrb_value ret = mrb_load_file(mrb, fp);
	}
	fclose(fp);

	mrb_close(mrb);
}
