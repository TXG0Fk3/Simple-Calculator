project('Simple Calculator', 'c')

dep = [dependency('gtk4'), dependency('libadwaita-1')]

gnome=import('gnome')
resources = gnome.compile_resources('resources','calculator.gresource.xml')

sourcefiles=files('src/main.c', 'src/calculator-window.c')

executable('tfe', sourcefiles, resources, dependencies: dep, install: false)
