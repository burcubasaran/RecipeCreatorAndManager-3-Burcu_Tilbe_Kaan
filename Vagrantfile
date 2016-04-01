# Automatically install plugin, taken from https://stackoverflow.com/questions/19492738/demand-a-vagrant-plugin-within-the-vagrantfile/36065867
required_plugins = %w( vagrant-exec )
required_plugins.each do |plugin|
  system "vagrant plugin install #{plugin}" unless Vagrant.has_plugin? plugin
end
Vagrant.configure(2) do |config|
  config.vm.box = "ubuntu/wily64"

  config.vm.network "forwarded_port", guest: 8080, host: 8080

  config.vm.provision :shell, path: "bootstrap.sh"

  config.exec.commands 'run', prepend: 'bash'
  config.exec.commands 'clean', prepend: 'bash'
end
