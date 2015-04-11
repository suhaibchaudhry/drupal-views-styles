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

    $options['animation_easing'] = array('default' => 'linear');

    $options['label_field'] = array('default' => '');

    return $options;
  }

function options_form(&$form, &$form_state) {
  parent::options_form($form, $form_state);

  // Pre-build all of our option lists for the dials and switches that follow.
  $fields = array('' => t('<None>'));
  foreach ($this->display->handler->get_handlers('field') as $field => $handler) {
    if ($label = $handler->label()) {
      $fields[$field] = $label;
    }
    else {
      $fields[$field] = $handler->ui_name();
    }
  }

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
    '#default_value' => $this->options['accordion_theme']
  );

  $form['content_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Content Height'),
    '#required' => TRUE,
    '#description' => t('Specify the Accordion Content Height'),
    '#default_value' => $this->options['content_height']
  );

  $form['header_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Header Size'),
    '#required' => TRUE,
    '#description' => t('Header size for verticle bar.'),
    '#default_value' => $this->options['header_size']
  );

  $form['header_font_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Header Font Size'),
    '#required' => TRUE,
    '#description' => t('Font size for verticle bar.'),
    '#default_value' => $this->options['header_font_size']
  );

   $form['activated_index'] = array(
    '#type' => 'textfield',
    '#title' => t('Active Item'),
    '#required' => TRUE,
    '#description' => t('The item that is active on page load, starting from 0.'),
    '#default_value' => $this->options['activated_index']
   );

   $form['animation_duration'] = array(
    '#type' => 'textfield',
    '#title' => t('Animation Duration'),
    '#required' => TRUE,
    '#description' => t('The amount of time in ms to run animation for.'),
    '#default_value' => $this->options['animation_duration']
   );

   $lib = libraries_detect('easing');
   $easing = array(
        "linear" => t('Linear'),
        "swing" => t('Swing')
   );

   if($lib['installed']) {
      $easing['easeInQuad'] = t('easeInQuad');
      $easing['easeOutQuad'] = t('easeOutQuad');
      $easing['easeInOutQuad'] = t('easeInOutQuad');
      $easing['easeInCubic'] = t('easeInCubic');
      $easing['easeInCubic'] = t('easeInCubic');
      $easing['easeInOutCubic'] = t('easeInOutCubic');
      $easing['easeInOutCubic'] = t('easeInOutCubic');
      $easing['easeOutQuart'] = t('easeOutQuart');
      $easing['easeInOutQuart'] = t('easeInOutQuart');
      $easing['easeInQuint'] = t('easeInQuint');
      $easing['easeOutQuint'] = t('easeOutQuint');
      $easing['easeInOutQuint'] = t('easeInOutQuint');
      $easing['easeInSine'] = t('easeInSine');
      $easing['easeOutSine'] = t('easeOutSine');
      $easing['easeInOutSine'] = t('easeInOutSine');
      $easing['easeInExpo'] = t('easeInExpo');
      $easing['easeOutExpo'] = t('easeOutExpo');
      $easing['easeInOutExpo'] = t('easeInOutExpo');
      $easing['easeInCirc'] = t('easeInCirc');
      $easing['easeOutCirc'] = t('easeOutCirc');
      $easing['easeInOutCirc'] = t('easeInOutCirc');
      $easing['easeInElastic'] = t('easeInElastic');
      $easing['easeOutElastic'] = t('easeOutElastic');
      $easing['easeInOutElastic'] = t('easeInOutElastic');
      $easing['easeInBack'] = t('easeInBack');
      $easing['easeOutBack'] = t('easeOutBack');
      $easing['easeInOutBack'] = t('easeInOutBack');
      $easing['easeInBounce'] = t('easeInBounce');
      $easing['easeOutBounce'] = t('easeOutBounce');
      $easing['easeInOutBounce'] = t('easeInOutBounce');
   }

   $form['animation_easing'] = array(
    '#type' => 'select',
    '#title' => t('Animation Easing'),
    '#required' => TRUE,
    '#options' => $easing,
    '#description' => t('Select an easing type for animation. Install jQuery Easing module and library to get all options.'),
    '#default_value' => $this->options['animation_easing']
  );

  $form['label_field'] = array(
    '#type' => 'select',
    '#title' => t('Label Field'),
    '#options' => $fields,
    '#default_value' => $this->options['label_field'],
    '#description' => t('Select the field that will be used as the label field for each accordion slide. If none is selected slides will be numbered by their index.'),
  );
}

//Validating the inputs
//@TODO validation
//seems to be a bug?

function options_validate(&$form, &$form_state) {

  parent::options_validate($form, $form_state);
  $options = &$form_state['values']['style_options'];

  if (!is_numeric($options['content_height'])) {
    form_error($form['content_height'], t('Please specify a numerical value for Content Height.'));
  }
  if (!is_numeric($options['header_size'])) {
      form_error($form['header_size'], t('Please specify a numerical value for Header Size.'));
  }
  if (!is_numeric($options['header_font_size'])) {
      form_error($form['header_font_size'], t('Please specify a numerical value for Header Font Size.'));
  }
  if (!is_numeric($options['activated_index'])) {
    form_error($form['activated_index'], t('Please specify a numerical value for Activated Index.'));
  }
  if (!is_numeric($options['animation_duration'])) {
    form_error($form['animation_duration'], t('Please specify a numerical value for Animation Druation.'));
  }
}

}