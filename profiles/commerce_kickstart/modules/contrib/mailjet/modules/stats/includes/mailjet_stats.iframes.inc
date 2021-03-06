<?php

/**
 * Iframe for the stats.
 */
function mailjet_stats_iframe() {
  if (!variable_get('mailjet_username') && !variable_get('mailjet_password')) {
    drupal_set_message(t('You need to add your Mailjet API details before you can continue'), 'warning');
    drupal_goto('admin/config/system/mailjet');
  }
  $token = variable_get("APItoken");
  if (!empty($token)) {
    global $base_url;
    $callbackurl = 'r=commerceguys&t='.$token.'&show_menu=none&u=Drupal-3.0';

    $default_url = IFRAME_URL."stats/?";

    return '<iframe src="' . $default_url . $callbackurl . '" width="100%" height="1080px" frameborder="0"></iframe>';
  }
  return t('Unable to generate registration form.');
}
