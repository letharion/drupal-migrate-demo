<?php
/**
 * @file
 * Migration class to create Speakers.
 */

class SpeakerMigration extends Migration {
  /**
   * Constructor does initialization of our migration.
   */
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('migrate_demo'));

    $columns = array();

    $options = array(
      'embedded_newlines' => TRUE,
    );
    $csv_file = 'sites/migrate.local/modules/migrate_demo/migrate_demo_part1/sessions_and_speakers.csv';

    // The example uses a CSV file as source.
    $this->source = new MigrateSourceCSV($csv_file, $columns, $options);
    // We migrate into "node" entities, speaker bundle.
    $this->destination = new MigrateDestinationNode('speaker');

    // We instantiate the MigrateMap.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'pgid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );
  }
}
