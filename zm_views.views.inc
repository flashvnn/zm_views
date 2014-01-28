<?php

/**
 * Implementation of hook_views_handlers() to register all of the basic handlers
 * views uses.
 */
function zm_views_views_handlers() {
	$module_path = drupal_get_path('module', 'zm_views');

  return array(
    'info' => array(
      'path' => $module_path . "/views/handlers",
    ),
    'handlers' => array(
      'zm_views_views_handler_argument_date' => array(
        'parent' => 'views_handler_argument_date',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data().
 */
function zm_views_views_data() {
  $data = array();

  $data['node']['created_date_less'] = array(
    'title' => t('Created date less than'),
    'help' => t('Date in the form of CCYYMMDD.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'zm_views_views_handler_argument_date',
    ),
  );

  $data['node']['created_date_greater'] = array(
    'title' => t('Created date greater than'),
    'help' => t('Date in the form of CCYYMMDD.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'zm_views_views_handler_argument_date_greater',
    ),
  );

  $data['node']['changed_date_less'] = array(
    'title' => t('Updated date less than'),
    'help' => t('Date in the form of CCYYMMDD.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'zm_views_views_handler_argument_date',
    ),
  );

  $data['node']['changed_date_greater'] = array(
    'title' => t('Updated date greater than'),
    'help' => t('Date in the form of CCYYMMDD.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'zm_views_views_handler_argument_date_greater',
    ),
  );

  return $data;
}
