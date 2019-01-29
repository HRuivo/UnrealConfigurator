# Unreal Configurator
Object display and configurator made in unreal with easy extensibility in mind.

Major aspects of the configurator can be customized by changing the data tables, allowing for a fast and easy extension of the application.

## Getting Started
### Adding new Configurable Objects
New types of objects for placement in the stand can be added to the CustomizableObjectsDataTable asset.
These objects will then be automatically loaded into the Object Selection Widget in runtime.

### Adding new materials
New materials can be added to the Material Selection Widget by inserting new entries into the MaterialCollectionDataTable.
These are loaded into the list of materials in the widget when the application is ran.

### Presets Saved as Json files
With extensibility and adaptation to external tools in mind, the presets are stored in json format. This could allow artists to configure a stand while inside a art content creation apps and exporting into a json file.


## Built With

* [Unreal Engine 4.21](https://www.unrealengine.com/)
