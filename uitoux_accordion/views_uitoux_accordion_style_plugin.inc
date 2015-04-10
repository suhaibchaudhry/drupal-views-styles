<?php

/**
 * @file
 * Views settings, output and data validation
 */


class views_uitoux_accordion_zozo_style_plugin extends views_plugin_style {
  
  //default options
  function option_definition() {
    $options = parent::option_definition();

    $options['accordion_theme']  =  array('default' => "crystal");
    $options['content_height'] =  array('default' => 150);

    $options['header_size']   = array('default' => 52);
    $options['header_font_size'] =  array('default' => '1.5');

    $options['activated_index'] =  array('default' => 0);

    $options['animation_duration'] =  array('default' => 600);

    return $options;
  }

function options_form(&$form, &$form_state) {
  parent::options_form($form, $form_state);

  unset($form['grouping']);
  //unset($form['type']);

  $form['accordion_theme'] = array(
    '#type' => 'select',
    '#title' => t('Accordion Theme'),
    '#required' => TRUE,
    '#options' => array(
      "crystal" => "Crystal",
      "gray" => "Gray",
      "black" => "Black", 
      "blue" => "Blue", 
      "white" => "White", 
      "lightblue" => "Light Blue", 
      "deepblue" => "Deep Blue",
      "green" => "Green",
      "yellow" => "Yellow",
      "purple" =>"Purple",
      "silver" => "Silver",
      "red" => "Red",
      "orange" =>"Orange",
      "clean" =>"Clean" 
    ),
    '#description' => t('Select an accordion theme.'),
    '#default_value' => $this->options['accordion_theme'],
  );

  $form['content_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Content Height'),
    '#required' => TRUE,
    '#description' => t('Specify the Accordion Content Height'),
    '#default_value' => $this->options['content_height'],
  );

  $form['header_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Header Size'),
    '#required' => TRUE,
    '#description' => t('Header size for verticle bar.'),
    '#default_value' => $this->options['header_size'],
  );

  $form['header_font_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Header Font Size'),
    '#required' => TRUE,
    '#description' => t('Font size for verticle bar.'),
    '#default_value' => $this->options['header_font_size'],
  );

   $form['activated_index'] = array(
    '#type' => 'textfield',
    '#title' => t('Active Item'),
    '#required' => TRUE,
    '#description' => t('The item that is active on page load, starting from 0.'),
    '#default_value' => $this->options['activated_index'],
   );

   $form['animation_duration'] = array(
    '#type' => 'textfield',
    '#title' => t('Animation Duration'),
    '#required' => TRUE,
    '#description' => t('The amount of time in ms to run animation for.'),
    '#default_value' => $this->options['animation_duration'],
   );
}

//Validating the inputs
//@TODO validation
//seems to be a bug?

function options_validate(&$form, &$form_state) {

  parent::options_validate($form, $form_state);
  $options = &$form_state['values']['style_options'];

  if (!is_numeric($options['max_width'])) {
    form_error($form['max_width'], t('Please specify a numerical value for Max Width'));
  }
  if (!is_numeric($options['min_width'])) {
      form_error($form['min_width'], t('Please specify a numerical value for Min Width'));
  }
  if (!is_numeric($options['animate_in'])) {
      form_error($form['animate_in'], t('Please specify a numerical value for Animate In'));
  }
  if (!is_numeric($options['animate_out'])) {
    form_error($form['animate_out'], t('Please specify a numerical value for Animate Out'));
  }
  if (!is_numeric($options['activated_item'])) {
    form_error($form['activated_item'], t('Please specify a numerical value for Activated Item'));
  }
   if (!is_numeric($options['caption_field_fadein'])) {
    form_error($form['activated_item'], t('Please specify a numerical value for fade in'));
  }
   if (!is_numeric($options['caption_field_fadeout'])) {
    form_error($form['activated_item'], t('Please specify a numerical value for fade out'));
  }
}

}