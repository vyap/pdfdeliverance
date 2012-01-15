<?php

function _deliver_form_steps() {
	return array(
		1 => array(
			'form' => 'deliver_form_select_product',
		),
		2 => array(
			'form' => 'deliver_form_uploud_file',
		),
		3 => array(
			'form' => 'deliver_form_license',
		),
	);
}

function _deliver_form($form, &$form_state) {
	if (empty($form_state['step'])) {
		$form_state['step'] = 1;
		$form_state['step_information'] = _deliver_form_steps();
	}
	
	$step = &$form_state['step'];
	drupal_set_title(t('Extensible Wizard: Step @step', array('@step' => $step)));
	$form = $form_state['step_information'][$step]['form']($form, $form_state);
	
	if ($step > 1) {
		$form['prev'] = array(
			'#type' => 'submit',
			'#value' => t('Previous'),
			'#name' => 'prev',
			'#submit' => array('deliver_form_previous_submit'),
		);
	}

	if ($step < count($form_state['step_information'])) {
		$form['next'] = array(
			'#type' => 'submit',
			'#value' => t('Next'),
			'#name' => 'next',
			'#submit' => array('deliver_form_next_submit'),
		);
	} else {
		$form['finish'] = array(
			'#type' => 'submit',
			'#value' => t('Finish'),
		);
	}

	return $form;
}

function deliver_form_previous_submit($form, &$form_state) {
	$current_step = &$form_state['step'];
	$form_state['step_information'][$current_step]['stored_values'] = $form_state['values'];
	if ($current_step > 1) {
		$current_step--;
		$form_state['values'] = $form_state['step_information'][$current_step]['stored_values'];
	}
	$form_state['rebuild'] = TRUE;
}

function deliver_form_next_submit($form, &$form_state) {
	$current_step = &$form_state['step'];
	$form_state['step_information'][$current_step]['stored_values'] = $form_state['values'];

	if ($current_step < count($form_state['step_information'])) {
		$current_step++;
		if (!empty($form_state['step_information'][$current_step]['stored_values'])) {
			$form_state['values'] = $form_state['step_information'][$current_step]['stored_values'];
		} else {
			$form_state['values'] = array();
		}
		$form_state['rebuild'] = TRUE;
		return;
	}
}

//Формы переходов. Каждую функцию нужно набить реальным функционалом

function deliver_form_select_product($form, &$form_state) {
  $form = array();
  $form['first_name'] = array(
    '#type' => 'textfield',
    '#title' => t('First Name'),
    '#default_value' => !empty($form_state['values']['first_name']) ? $form_state['values']['first_name'] : '',
  );
  $form['last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Last Name'),
    '#default_value' => !empty($form_state['values']['last_name']) ? $form_state['values']['last_name'] : '',
  );
  return $form;
}

function deliver_form_uploud_file($form, &$form_state) {
  $form = array();
  $form['city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#description' => t('Hint: Do not enter "San Francisco", and do not leave this out.'),
    '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['city']) ? $form_state['values']['city'] : '',

  );
  return $form;
}

function deliver_form_license($form, &$form_state) {
  $form = array();
  $form['aunts_name'] = array(
    '#type' => 'textfield',
    '#title' => t("Your first cousin's aunt's Social Security number"),
    '#default_value' => !empty($form_state['values']['aunts_name']) ? $form_state['values']['aunts_name'] : '',
  );
  return $form;
}

function deliver_form_submit($form, &$form_state) {
  $current_step = &$form_state['step'];
  $form_state['step_information'][$current_step]['stored_values'] = $form_state['values'];

  drupal_set_message(t('This information was collected by this wizard:'));
  foreach ($form_state['step_information'] as $index => $value) {
    unset($value['stored_values']['form_id']);
    unset($value['stored_values']['form_build_id']);
    unset($value['stored_values']['form_token']);

    drupal_set_message(t('Step @num collected the following values: <pre>@result</pre>', array('@num' => $index, '@result' => print_r($value['stored_values'], TRUE))));
  }
}
