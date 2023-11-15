project('Simple Calculator', 'c')

gtkdep = dependency('gtk4')
adwdep = dependency('libadwaita-1')

gnome=import('gnome')
resources = gnome.compile_resources('resources','src/calculator.gresource.xml')

sourcefiles=files('src/main.c', 'src/calculator-window.c', 'src/calculate.c')

executable('SimpleCalculator', sourcefiles, resources, dependencies: [gtkdep, adwdep], install: false)
