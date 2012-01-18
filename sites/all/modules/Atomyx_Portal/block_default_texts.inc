<?php 

function set_default_blocks_texts() {
	$variable_set = "
		<p>
			Congratulations, you uploaded your files to our server. But before you break out the champage, let's make sure those files will give the result you expect...
		</p>
		<p>
			As soon as we receive your files, we'll do extensive quality control on them so that we're certain we can print them without nasty surprises. That process is called preflight. If we find any problems, we'll tell you what they are and if we can correct them or you have to. And finally, we'll show you how the files look one last time and you can accept or reject delivery.
		</p>
		<p>
			Click the \"continue\" button below and we'll take you to the 'Jobs' list. You'll see the files you just uploaded and as soon as we had a chance to check them, you'll be able to see each of them to complete delivery. It'll only take a second! 
		</p>
		<p>
			Once you complete delivery you'll also see a \"Job ID\" appear in the list of jobs. This is a unique number for your job. If you need to contact us about your order, simply quote that number and we'll be on the same page...
		</p>
	";
	variable_set('job_actions_help_default', $variable_set);

}
