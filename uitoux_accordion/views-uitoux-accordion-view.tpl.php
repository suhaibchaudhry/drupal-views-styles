<?php
/**
 * @file views-uitoux-accordion-view.tpl.php
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 * 
 * @TODO Put the first/last logic into module code
 * @TODO put the active classes logik somehow into module code not here
 */
?>
<div id="uitoux-accordion" class="views_uitoux_accordion views_uitoux_accordion-<?php print $view->vid; ?>">
  <ul class="views-uitoux-accordion">
    <?php foreach ($rows as $id => $row): ?>
      <li>
        <h3><?php print $tab_titles[$id]; ?></h3>
        <div>
          <?php print $row; ?>
        </div>
      </li>
    <?php endforeach; ?>
  </ul>
</div>
