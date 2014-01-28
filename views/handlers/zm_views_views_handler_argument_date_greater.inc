<?php
/**
 * Extend views handle date.
 */
class zm_views_views_handler_argument_date_greater extends zm_views_views_handler_argument_date {
  /**
   * Constructor implementation
   */
  function construct() {
    parent::construct();
    $this->operation = '>';
  }
}
