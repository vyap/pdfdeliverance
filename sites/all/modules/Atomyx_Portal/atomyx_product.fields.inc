<?php

	function _product_node_installed_fields() {

		return array(
			'field__name' => array(
				'field_name'  => 'field__name',
				'cardinality' => 1,
				'type'        => 'text',
				'settings'    => array(
				'max_length'  => 60,
			),
		),

			'field__visible' => array(
				'field_name' => 'field__visible',
				'type'       => 'list_boolean',
				'settings' => array(
					'allowed_values'=> array(
						0 => '0',
						1 => '1',
					),
				),
				'cardinality' => 1,
			),

			'field__description' => array(
				'field_name'  => 'field__description',
				'cardinality' => 1,
				'type'        => 'text',
			),

			'field__image' => array(
				'field_name'  => 'field__image',
				'cardinality' => 1,
				'type'        => 'image',
			),

			'field__metadata' => array(
				'field_name' => 'field__metadata',
				'type'       => 'table',
				'cardinality' => 1,
			),

			'field___reporttype' => array(
				'field_name'  => 'field__reporttype',
				'type'        => 'list_text',
				'cardinality' => 1,
				'settings'    =>array(
					'allowed_values'=>array(
						'XML'      => 'XML report',
						'MASK'     =>'PDF report, problems highlighted by transparent masks',
						'COMMENT'  =>'PDF report, problems highlighted by annotations',
						'LAYER'    =>'PDF report, problems separated on layers',
						'INVENTORY'=>'PDF report which lists all resources used in the PDF file',
						'COMPARE'  =>'PDF compare reports',
					),
				),
			),

			'field__lowrespdf' => array(
				'field_name' => 'field__lowrespdf',
				'type'       => 'list_boolean',
				'settings'   =>array(
					'allowed_values'=>array(
						0 => '0',
						1 => '1',
					),
				),
				'cardinality' => 1,
			),

			'field__profile' => array(
				'field_name' => 'field__profile',
				'type'       => 'file',
				'settings'   => array(
					'allowed_values' => array(
						0 => '0',
						1 => '1',
					),
				),
				'cardinality' => 1,
			),

			'field__lowpreflight' => array(
				'field_name'  => 'field__lowpreflight',
				'type'        => 'file',
				'cardinality' => 1,
			),

			'field__allow_pdf_fix' => array(
				'field_name' => 'field__allow_pdf_fix',
				'type'       => 'list_boolean',
				'settings'   => array(
					'allowed_values' => array(
						0 => '0',
						1 => '1',
					),
				),
				'cardinality' => 1,
			),

			'field__num_of_pages' => array(
				'field_name' => 'field__num_of_pages',
				'type'       => 'list_text',
				'settings'   =>array(
					'allowed_values'=>array(
						'1' => '1',
						'2' => '2',
						'5' => '5',
						'10'=> '10',
					),
				),
				'cardinality' => 1,
			),

			'field__regular' => array(
				'field_name' => 'field__regular',
				'type'       => 'text',
				'cardinality'=> 1,
			),
		);
	}

	function _product_node_installed_instances() {
		return array(
			'field__name' => array(
				'field_name'  => 'field__name',
				'label'       => t('Product name:'),
				'required'    => TRUE,
				'widget'      => array(
					'type'    => 'text_textnode',
				),
				'display'     => array(
					'atomyx_portal_node_list' => array(
						'label' => 'above',
						'type'  => 'text',
					),
				),
			),

			'field__visible' => array(
				'field_name'  => 'field__visible',
				'label'       => t('Visible'),
				'widget'      => array(
					'type'    => 'options_onoff',
					'settings'=> array(
						'display_label' =>1,
					),
				),
				'display'     => array(
					'atomyx_portal_node_list' => array(
						'label' => 'above',
						'type'  => 'list_default',
					),
				),
			),

			'field__description' => array(
				'field_name'  => 'field__description',
				'label'       => t('Description'),
				'required'    => TRUE,
				'widget'      => array(
					'type' => 'text',
				),
				'display'     => array(
					'atomyx_portal_node_list' => array(
						'label' => 'above',
						'type'  => 'text',
					),
				),
			),

			'field__image' => array(
				'field_name'  => 'field__image',
				'label'       => t('Product logo'),
				'required'    => TRUE,
				'widget'      => array(
					'type' => 'image_image',
				),
				'display'     => array(
					'atomyx_portal_node_list' => array(
						'label' => 'hidden',
						'type'  => 'image_link_content__thumbnail',
					),
				),
			),

			'field__metadata' => array(
				'field_name'  => 'field__metadata',
				'label'       => t('Metadata (5 columns required)'),
				'required'    => TRUE,
				'widget'      => array(
					'type'     => 'cck_table_textarea',
					'settings' => array(
						'rows'                 =>5,
						'separator'            =>'|',
						'enforce_misalign_col' =>1,
					),
				),
				'display'     => array(
					'atomyx_portal_node_list' => array(
						'label' => 'above',
						'type' => 'without_header',
					),
				),
			),

			'field__reporttype' => array(
				'field_name'  => 'field__reporttype',
				'label'       => t('Report type.'),
				'required'    => TRUE,
				'widget'      => array(
					'type' => 'options_select',
				),
				'display'     => array(
					'atomyx_portal_node_list' => array(
						'label' => 'above',
						'type'  => 'list_default',
					),
				),
			),

			'field__lowrespdf' => array(
				'field_name'   => 'field__lowrespdf',
				'label'        => t('Low resolution pdf'),
				'widget'       => array(
					'type' => 'options_onoff',
					'settings' => array(
						'display_label' =>1,
					),
				),
				'display'      => array(
					'atomyx_portal_node_list' => array(
						'label' => 'above',
						'type'  => 'list_default',
					),
				),
			),

			'field__profile' => array(
				'field_name' => 'field__profile',
				'label'      => t('Profile'),
				'required'   => TRUE,
				'widget'     => array(
					'type' => 'file_generic',
				),
				'settings'   => array(
					'file_directory'  => '',
					'file_extensions' =>'kfpx',
					'max_filesize'    => '200MB',
				),
				'display'    => array(
					'atomyx_portal_node_list' => array(
						'label' => 'above',
						'type'  => 'file_default',
					),
				),
			),

			'field__lowpreflight' => array(
				'field_name'  => 'field__lowpreflight',
				'label'       => t('Lowpreflight kfpx'),
				'widget'      => array(
					'type' => 'file_generic',
				),
				'settings'    => array(
					'file_directory'  => '',
					'file_extensions' => 'kfpx',
					'max_filesize'    => '200MB',
				),
				'display'     => array(
					'atomyx_portal_node_list' => array(
						'label' => 'above',
						'type'  => 'file_default',
					),
				),
			),

			'field__allow_pdf_fix' => array(
				'field_name'  => 'field__allow_pdf_fix',
				'label'       => t('Allow pdf file fixing'),
				'widget'      => array(
					'type'    => 'options_onoff',
					'settings'=> array(
						'display_label' =>1,
					),
				),
				'display'     => array(
					'atomyx_portal_node_list' => array(
						'label' => 'above',
						'type'  => 'list_default',
					),
				),
			),

			'field__num_of_pages' => array(
				'field_name'  => 'field__num_of_pages',
				'label'       => t('Number of pages'),
				'widget'      => array(
					'type'    => 'options_select',
				),
				'display'     => array(
				'atomyx_portal_node_list' => array(
					'label' => 'above',
					'type'  => 'list_default',
					),
				),
			),

			'field__regular' => array(
				'field_name' => 'field__regular',
				'label'      => t('Regular expression for job files upload'),
				'required'   => TRUE,
				'widget'     => array(
					'type' => 'text_textnode',
				),
				'display'    => array(
					'atomyx_portal_node_list' => array(
						'label' => 'above',
						'type'  => 'text_default',
					),
				),
			),
		);
	}
