-------------------------------------------------------------------------------
  MAQAO v2.2 

       Modular Assembly Quality Analyzer and Optimizer - v2.2

-------------------------------------------------------------------------------


INSTALLATION:
-------------------------------------------------------------------------------

smaqao is an executable for Linux X86-64 bit platform


GETTING STARTED:
-------------------------------------------------------------------------------

-  smaqao batch=on module=instrumenter mode=instrument input=<file.lua> 


Where <file.lua> specify the kind of instrumentation to apply


EXAMPLES
-------------------------------------------------------------------------------
%cat tau.lua

return {
  run_dir = "DIRECTORY_TO_DUMP_INSTRUMENTATION_RESULTS",
  at_entry={
      {
	    name = "trace_register_func",
	    lib = "libTauHooks.so",
	   	foreach_function = true,
	    params = {
	      {type = "macro",value = "fct_info_summary"},
	      {type = "macro",value = "profiler_id"}
	    }
	  }
  },
  at_exit={
	  {
	    name = "tau_dyninst_cleanup",
	    lib = "libTauHooks.so"
	  }
  },  
  main_bin = {
		properties={
			synchronize_beforeandafter_calls = true
		},  
		path= "FULL PATH TO THE BINARY TO INSTRUMENT",
		output_suffix = "_inst",
		fct_entries={
			{
				name = "traceEntry",
				lib = "libTauHooks.so",
				params = {
						{type = "macro",value = "profiler_id"}
				}
			}
		},
		fct_exits={
			{
				name = "traceExit",
				lib = "libTauHooks.so",
				params = {
						{type = "macro",value = "profiler_id"}
				}
			}
		},
		exceptions={}  	
  },
  libs = {
  	{
		properties={},	
  	path = "FULL PATH TO THE SHARED LIB TO INSTRUMENT",
  	output_suffix = "_inst",
		fct_entries={
		  {
		    name = "traceEntry",
		    lib = "libTauHooks.so",
		    params = {
		        {type = "macro",value = "profiler_id"}
		    }
		  }
		},
		fct_exits={
		  {
		    name = "traceExit",
		    lib = "libTauHooks.so",
		    params = {
		        {type = "macro",value = "profiler_id"}
		    }
		  }
		},
		exceptions={}  		
  	}
  }
};



CONTACT
-------------------------------------------------------------------------------
Please visit www.maqao.org for more information
