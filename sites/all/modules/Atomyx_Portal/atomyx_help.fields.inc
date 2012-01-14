<?php

	function _node_atomhelp_installed_fields() 
	{
		$t = get_t();
		return array(
			'field_helpbody'  => array(
				'field_name'  => 'field_helpbody',
				'cardinality' => 1,
				'type'        => 'text_with_summary',
			),

			'field_helppage' => array(
				'field_name'    => 'field_helppage',
				'type'          => 'list_text',
				'cardinality'   => 1,
				'settings'      =>array(
					'allowed_values'=>array(
						'all'       => 'all',
						''          => 'home',
						'myproducts'=> 'myproducts',
						'deliver'   => 'deliver',
						'closer'    => 'closer',
						'bummer'    => 'bummer',
						'close'     => 'close',
						'success'   => 'success',
						'jobs'      => 'jobs',
						'license'   => 'license',
						'upload'    => 'upload',
						'approve'   => 'approve',
						'mydelivery'=> 'mydelivery',
						'closecall'=> 'closecall',
						'change'=> 'change',
						'welcome'=> 'welcome',
					),
				),
			),

			'field_helpweight' => array(
				'field_name'   => 'field_helpweight',
				'cardinality'  => 1,
				'type'         => 'text',
				'settings'     => array(
					'max_length' => 60,
				),
			),
		); 
	}
 

	function _node_atomhelp_installed_instances()
	{
		$t = get_t();
		return array(  
			'field_helpbody'  => array(
				'field_name'  => 'field_helpbody',
				'label'       => $t('Body:'),
				'required' => TRUE,
				'widget'      => array(
					'type'    => 'text_textarea_with_summary',
				),
				'display'     => array(
					'atomhelp_node_list' => array(
						'label' => 'above',
						'type'  => 'text_textnode',
					),
				),
			),

			'field_helppage' => array(
				'field_name' => 'field_helppage',
				'label'      => $t('Page:'),
				'required'   => TRUE,
				'widget'     => array(
					'type' => 'options_select',
				),
				'display'    => array(
					'atomhelp_node_list' => array(
						'label' => 'above',
						'type'  => 'list_default',
					),
				),
			),

			'field_helpweight' => array(
				'field_name'   => 'field_helpweight',
				'label'        => $t('Weight:'),
				'required'     => TRUE,
				'widget'       => array(
					'type' => 'text_textnode',
				),
				'display'      => array(
					'atomhelp_node_list' => array(
						'label' => 'above',
						'type'  => 'text',
					),
				),
			),
		);
	   
	}
