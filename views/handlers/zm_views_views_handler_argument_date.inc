<?php
/**
 * Extend views handle date.
 */
class zm_views_views_handler_argument_date extends views_handler_argument_date {
	var $operation = '<';
  /**
   * Constructor implementation
   */
  function construct() {
    parent::construct();
    $this->format = 'F j, Y';
    $this->arg_format = 'Ymd';
    $this->formula = views_date_sql_format($this->arg_format, "***table***.$this->real_field");
  }

  /**
   * Provide a link to the next level of the view
   */
  function summary_name($data) {
    $created = $data->{$this->name_alias};
    return format_date(strtotime($created . " 00:00:00 UTC"), 'custom', $this->format, 'UTC');
  }

  /**
   * Provide a link to the next level of the view
   */
  function title() {
    return format_date(strtotime($this->argument . " 00:00:00 UTC"), 'custom', $this->format, 'UTC');
  }
  /**
   * Build the query based upon the formula
   */
  function query($group_by = FALSE) {
    $this->ensure_my_table();
    // Now that our table is secure, get our formula.
    $placeholder = $this->placeholder();
    $formula = $this->get_formula() .' '.$this->operation.' ' . $placeholder;
    $placeholders = array(
      $placeholder => $this->argument,
    );
    $this->query->add_where(0, $formula, $placeholders, 'formula');
  }

}
