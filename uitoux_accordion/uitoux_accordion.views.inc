<?php
// $Id$

/**
 * @file
 * Provide views data and handlers for uitoux_accordion.module *  
 */

/*
 * Implementation of hook_views_plugins()
 * IMPORTANT, theme is the name of the tpl with - replaced by _
 * views-uitoux-accordion-view.tpl.php -> views_uitoux_accordion_view
 */
function uitoux_accordion_views_plugins() {
  return array(
    'module' => 'uitoux_accordion',
    'style' => array (
        'uitoux_accordion_zozo' => array(
          'title' => t('UIToUX Zozo Accordion'),
          'help' => t('Displays Content with a Horizontal Slider Effect.'),
          'handler' => 'views_uitoux_accordion_zozo_style_plugin',
          'uses row plugin' => TRUE,
          'uses options' => TRUE,
          'uses grouping' => FALSE,
          'type' => 'normal',
          'path' => drupal_get_path('module', 'uitoux_accordion'),
          'theme path' => drupal_get_path('module', 'uitoux_accordion'),
          'theme' => 'views_uitoux_accordion_view',
        ),
    ),
  );
}